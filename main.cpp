#include "dll.hpp"


void compress(string filename) {
    unsigned int ones = 0;
    unsigned int zeros = 0;

    std::ifstream file(filename, ios::binary);
    if (file.is_open()) {
        char byte;
        vector<bool> bools;
        while (file.get(byte)) {
            // Process the byte, e.g., print its bits
            for (int i = 7; i >= 0; --i) {
                bool test = (byte >> i) & 1;
                bools.emplace_back(test);
                if (test) ones++;
                else zeros++;
            }
        }

        ofstream out("output.cps");
        if (out.is_open()) {
            CryptoPP::HexEncoder encoder(new CryptoPP::FileSink(out));
            out << ones << endl;
            out << zeros << endl;
            CryptoPP::BLAKE2b hash;
            string st = "";
            string output;
            output.resize(hash.DigestSize());
            for (size_t i = 0; i < bools.size(); i++) {
                st += bools[i];
            }

            hash.Update((const CryptoPP::byte*)st.data(), st.size());
            hash.Final((CryptoPP::byte*)&output[0]);
            CryptoPP::StringSource(output, true, new CryptoPP::Redirector(encoder));
            out << endl;

        }

        file.close();
    } else {
        std::cerr << "Error opening file!" << std::endl;
    }
}

void decompress(string filein, string fileout) {
    ifstream in(filein);
    if (in.is_open()) {
        unsigned int ones;
        unsigned int zeros;
        string hash;
        in >> ones;
        in >> zeros;
        in >> hash;
        cout << ones << endl << zeros << endl << hash << endl;
        DLinkedList dll = DLinkedList(ones, zeros);
        string text = dll.toString();
        cout << text << endl;
        /*will be used later*/
        int movingOnes = ones;
        int pos = zeros;
        for (unsigned int i = 0; i < zeros; i++) {
            dll.moveNNodesLeft(ones, pos);
            text = dll.toString();
            cout << text << endl;
            pos--;
        }

    }
}




int main() {
    string filename = "input.txt"; // Specify your input file here
    compress(filename);
    decompress("output.cps", "fileout.txt");
    return 0;
}