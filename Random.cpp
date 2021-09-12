vector<int> temp;
for (auto i : v)
    temp.insert(temp.end(), i.begin(), i.end());
sort(temp.begin(), temp.end());

int counter = 0;
for (int i = 0; i < v.size(); i++)
{
    for (int j = 0; j < v[i].size(); j++)
    {
        v[i][j] = temp[counter++];
    }
}
return v;