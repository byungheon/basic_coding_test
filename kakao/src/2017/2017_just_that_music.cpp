#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int stringToTime(string str) {
    int hour = stoi(str.substr(0, 2));
    int min = stoi(str.substr(3, 2));

    return hour * 60 + min;
}

//string convertSharp(string notes)
//{
//    string ret = "";
//    const int diff = 'A' - 'a';
//    for (int i = 0; i < notes.size(); i++)
//    {
//        if (i < notes.size() - 1 && notes.at(i + 1) == '#')
//        {
//            ret.push_back((char)(notes.at(i) - diff));
//            i++;
//        }
//        else
//        {
//            ret.push_back(notes.at(i));
//        }
//    }
//    return ret;
//}

string convertSharp(string notes)
{
    string ret = "";

    int ret_idx = 0;
    for (size_t i = 0; i < notes.length(); i++)
    {
        if (notes[i] == '#') {
            ret[ret_idx - 1] = tolower(ret[ret_idx - 1]);
        }
        else {
            ret.push_back(notes[i]);
            ret_idx++;
        }
    }

    return ret;
}

string solution(string z, vector<string> musicinfos) {
    string answer = "(None)";
    int answer_time = 0;
    int time_step = 5;

    string m = convertSharp(z);
    for (size_t i = 0; i < musicinfos.size(); i++)
    {
        int start_time = stringToTime(musicinfos[i].substr(0, time_step));
        int end_time = stringToTime(musicinfos[i].substr(time_step+1, time_step));
        int time_gap = end_time - start_time;
        
        //const int maxTime = 24 * 60;
        //int begin = stoi(musicinfos[i].substr(0, 2)) * 60 + stoi(musicinfos[i].substr(3, 2));
        //int end = stoi(musicinfos[i].substr(6, 2)) * 60 + stoi(musicinfos[i].substr(9, 2));    
        ////int runLength = begin >= maxTime ? 0 : min(maxTime, end) - begin;
        //int runLength = end - begin;
        ////if (m.length() > runLength)
        ////    continue;

        int comma_idx = 0;
        for (size_t j = time_step * 2 + 2; j < musicinfos[i].length(); j++)
        {
            if (musicinfos[i][j] == ',')
                comma_idx = j - (time_step * 2 + 2);
        }

        string music_name = musicinfos[i].substr(time_step * 2 + 2, comma_idx);
        string music = convertSharp(musicinfos[i].substr(time_step * 2 + 2 + comma_idx + 1));

        //string music_name = musicinfos[i].substr(12, musicinfos[i].rfind(',') - 12);
        //int notePtr = 13 + music_name.size();
        //int noteLength = musicinfos[i].size() - notePtr;
        //string music = convertSharp(musicinfos[i].substr(notePtr, noteLength));

        //string flow = "";
        //int note_length = music.length();
        //for (int r = 0; r < time_gap / note_length; r++)
        //{
        //    flow = flow.append(music);
        //}
        //flow = flow.append(music, 0, time_gap % note_length);

        string flow = music;
        while (flow.length() < time_gap) {
            flow += music;
        }
        flow = flow.substr(0, time_gap);

        std::size_t found = flow.find(m);
        if (found != std::string::npos) {
            if (time_gap > answer_time) {
                answer = music_name;
                answer_time = time_gap;
            }
        }
    }
    return answer;
}

int main() {
    string m = "CC#BCC#BCC#BCC#B";
    std::vector<string> musics = {"03:00,03:30,FOO,CC#B", 
    "04:00,04:08,BAR,CC#BCC#BCC#B"};

    string ans = solution(m, musics);

    return 0;
}