#include <string>
#include <vector>
#include <set>
#include <map>

using namespace std;

int PrefixMatch(vector<string> cmds, set<string> &uniq_prefix_cmds)
{
    uniq_prefix_cmds.clear();
    for (unsigned int i = 0; i < cmds.size(); i++)
    {
        bool find_prefix = false;
        string substring;
        for (unsigned int j = 1; j <= cmds[i].size(); j++)
        {
            substring = cmds[i].substr(0, j);

            if (uniq_prefix_cmds.find(substring) != uniq_prefix_cmds.end())
            {
                find_prefix = true;
                break;
            }
        }
        if (find_prefix == false)
        {
            uniq_prefix_cmds.insert(cmds[i]);
        }
    }
    return 0;
}

int ParseParam(string param, string &argu, map<string, string> &kv)
{
    if (param.empty())
        return 0;
    kv.clear();

    // argu
    size_t pos = param.find(" ");
    if (pos != string::npos)
    {
        argu = param.substr(0, pos);
    }

    size_t pos_start = param.find("-", pos + 1);
    size_t pos_end = 0;
    while (pos_start != string::npos)
    {
        pos_end = param.find("-", pos_start + 1);

        size_t len = ((pos_end == string::npos) ? param.size() : pos_end) - pos_start;
        string subkv = param.substr(pos_start, len);
        // printf("pos_start:%lu,pos_end:%lu,len:%lu,subkv:%s\n",pos_start,pos_end,len,subkv.c_str());

        // parse kv
        size_t space_pos = subkv.find(" ");
        if (space_pos == string::npos)
        {
            // printf("subkv:%s\n", subkv.c_str());
            return -1;
        }

        string k = subkv.substr(0, space_pos);
        space_pos++;
        while (space_pos < subkv.size() && subkv[space_pos] == ' ')
            space_pos++;
        kv.insert(make_pair(k, subkv.substr(space_pos)));

        pos_start = pos_end;
    }

    return 0;
}
int test_prefix_match()
{
    vector<string> cmds;
    set<string> uniq_prefix_cmds;

    cmds.push_back("strategy");
    cmds.push_back("read1");
    cmds.push_back("write1");
    cmds.push_back("read2");
    cmds.push_back("read23");
    cmds.push_back("strategy info");
    cmds.push_back("strategy add");
    cmds.push_back("strategy rm");

    (void)PrefixMatch(cmds, uniq_prefix_cmds);
    set<string>::iterator s_it = uniq_prefix_cmds.begin();
    for (; s_it != uniq_prefix_cmds.end(); s_it++)
    {
        printf("%s\n", s_it->c_str());
    }
    return 0;
}

int test_ParseParam()
{
    string param0 = "yutaoli -h /home/yutaoli -s /bin/shell";
    string param1 = "-h /home/yutaoli -s /bin/shell yutaoli ";

    string param2 = "yutaoli -h  -s /bin/shell ";
    string param3 = "-h  -s /bin/shell yutaoli ";

    string param = param2;

    string argu;
    map<string, string> kv;
    int ret = ParseParam(param, argu, kv);
    if (ret != 0)
    {
        printf("help ParseParam\n");
        return -1;
    }

    printf("%s\n", argu.c_str());

    map<string, string>::iterator m_kv_it;
    for (m_kv_it = kv.begin();
         m_kv_it != kv.end();
         m_kv_it++)
    {
        printf("k:%s,v:%s\n", m_kv_it->first.c_str(), m_kv_it->second.c_str());
    }

    return 0;
}
int main()
{
    // test_prefix_match();
    test_ParseParam();
    return 0;
}