class Solution {
public:
  int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
    vector<int> month_days = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    vector<int> pref(13, 0);
    pref[1] = 31;
    for (int i = 2; i <= 12; i++) {
      pref[i] = pref[i - 1] + month_days[i - 1];
    }
    auto find_days = [&](string& date) -> int {
      int month = stoi(date.substr(0, 2));
      int days = stoi(date.substr(3));
      return pref[month - 1] + days;
    };
    int arriveAliceDays = find_days(arriveAlice);
    int leaveAliceDays = find_days(leaveAlice);
    int arriveBobDays = find_days(arriveBob);
    int leaveBobDays = find_days(leaveBob);
    int overlap_days = min(leaveAliceDays, leaveBobDays) - max(arriveAliceDays, arriveBobDays) + 1;
    return overlap_days < 0 ? 0 : overlap_days;
  }
};
