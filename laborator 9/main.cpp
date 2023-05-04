#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>


using namespace std;
class Episode {
public:
    Episode(string title,string date, int length, int viewersmm, double score) : title_(move(title)), date_(move(date)), length_(length), viewersmm_(viewersmm), score_(score) {}

    string const& get_title() const { return title_; }
    string const& get_date() const { return date_; }
    int get_length() const { return length_; }
    int get_viewersmm() const { return viewersmm_; }
    double get_score() const { return score_; }

private:
    string title_;
    string date_;
    int length_;
    int viewersmm_;
    double score_;
};

class CsvReader {
public:
    
    explicit CsvReader(istream& input_file) : input_file_(input_file) {}
    ~CsvReader() = default;

    class CsvIterator {
    public:

        CsvIterator(CsvReader& reader, bool end) : reader_(reader), current_line_(""), is_end_(end) {}
        CsvIterator(const CsvIterator&) = default;
        CsvIterator& operator=(const CsvIterator&) = default;
        ~CsvIterator() = default;

        CsvIterator& operator++();
        vector<string> operator*() const;
        bool operator!=(const CsvIterator& other) const;

    private:
        CsvReader& reader_;
        string current_line_;
        bool is_end_;
    };

    CsvIterator begin();
    CsvIterator end();

private:
    istream& input_file_;
};

CsvReader::CsvIterator CsvReader::begin() {
    input_file_.seekg(0);
    return CsvIterator(*this, false);
}

CsvReader::CsvIterator CsvReader::end() {
    return CsvIterator(*this, true);
}

CsvReader::CsvIterator& CsvReader::CsvIterator::operator++() {
    if (getline(reader_.input_file_, current_line_)) {
        while (current_line_.empty() && !reader_.input_file_.eof()) {
            getline(reader_.input_file_, current_line_);
        }
    }
    else {
        is_end_ = true;
    }
    return *this;
}

vector<string> CsvReader::CsvIterator::operator*() const {
    vector<string> columns;
    stringstream ss(current_line_);
    string column;
    while (getline(ss, column, ',')) {
        if (!column.empty() && column.front() == '"' && column.back() == '"') {
            column = column.substr(1, column.size() - 2);
        }
        columns.push_back(column);
    }
    return columns;
}

bool CsvReader::CsvIterator::operator!=(const CsvIterator& other) const {
    return &(reader_.input_file_) != &(other.reader_.input_file_) || current_line_ != other.current_line_ || is_end_ != other.is_end_;
}

int main() {
    ifstream input_file("episodes.csv");
    if (!input_file.is_open()) {
        cout << "File couldn't be opened\n";
        return 1;
    }

    CsvReader reader(input_file);
    vector<Episode> episodes;

    for (vector<string> columns : reader) {
        if (columns.size() >= 5) {
            Episode episode(columns[0], columns[1], stoi(columns[2]), stof(columns[3]), stof(columns[4]));
            episodes.push_back(episode);
        }
        else {
            cout << "Episodes added to output.txt\n";
        }
    }

    cout << "number of episodes: " << episodes.size() << "\n\n";

    ofstream output_file("output.txt");
    for (auto& episode : episodes) {
        output_file << "Title: " << episode.get_title() << "\n";
        output_file << "Date: " << episode.get_date() << "\n";
        output_file << "Length: " << episode.get_length() << " minutes\n";
        output_file << "Viewers: " << episode.get_viewersmm() << " million\n";
        output_file << "Score: " << episode.get_score() << "\n\n";
    }

    output_file.close();

    return 0;
}
