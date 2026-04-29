// history.c 
// written by dao  99.5
// in 15 min, new created id should be limited
// 防止利用频繁登录/自杀选择天赋 

inherit F_CLEAN_UP;

#include <ansi.h>

mapping newid_iplist;

#define MAX_IP_USER_CREATE	10
#define MAX_WHOLE_USER_CREATE	100
void create()
{
	newid_iplist = ([ ]);
}


int valid_ip_newid(string ip) {
	if ( ! ip) return 0;
	if(sizeof(newid_iplist) > MAX_WHOLE_USER_CREATE ) return -1;
	if( newid_iplist[ip] > MAX_IP_USER_CREATE ) return -2;
	else return 1;
}

int add_ip_newid(string ip) {
	if(!ip) return 0;
	if(sizeof(newid_iplist) > MAX_WHOLE_USER_CREATE ) return -1;
	newid_iplist[ip] ++;
	return 1;
}

void show_newid_iplist() {

	string list= "最近新注册玩家IP分布：\n";
	string *ipl;
	int i;

	ipl = keys(newid_iplist);
	for(i=0;i< sizeof(ipl);i++) {
		list = list + ipl[i] + ":\t\t" + newid_iplist[ipl[i]] + "\n";
	}
	this_player()->start_more(list);
}
