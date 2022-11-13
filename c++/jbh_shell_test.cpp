#include <string>
#include <vector>
#include <set>

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
int main()
{
    test_prefix_match();
    return 0;
}