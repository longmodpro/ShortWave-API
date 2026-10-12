// C++17 helper: validates media file signature; optional tool, not required for Node runtime.
#include <fstream>
#include <iostream>
#include <string>
int main(int argc,char**argv){if(argc!=2){std::cerr<<"Usage: media_probe <file>\n";return 2;}std::ifstream f(argv[1],std::ios::binary);char b[12]{};f.read(b,12);if(f.gcount()<12)return 1;std::string s(b,12);bool mp4=s.substr(4,4)=="ftyp";bool webm=(unsigned char)b[0]==0x1a&&(unsigned char)b[1]==0x45&&(unsigned char)b[2]==0xdf&&(unsigned char)b[3]==0xa3;std::cout<<(mp4?"MP4":webm?"WebM":"Unknown")<<"\n";return mp4||webm?0:1;}
