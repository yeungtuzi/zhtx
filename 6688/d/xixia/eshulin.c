// Room: /d/xixia/npc/eshulin.c

#include <ansi.h>

inherit ROOM;

string *str = ({
 "你心里感概万千：可怜史长老一生行侠仗义，死时还念念不忘送信之事，却没来地及说出凶手姓名。\n",
"不过天下高手虽多，但杀得了史长老的寥寥无几，此人又精通少林绝技散花掌，应该不难查。\n",
"你暗暗发誓要替史长老报仇，虽然这是丐帮自己的事，但总是因你而起。\n",
"不过当前最要紧的是如何阻止赫连铁树围剿丐帮大会，二十个御前士卫倒没什么，一品堂和一千五的铁鹞军伏兵可不是闹着玩的！况且西夏一品堂的悲酥清风。。。\n",
"掐指一算，今天离丐帮大会只有两天期限了，给丐帮送信已经来不及了，这如何是好？难道丐帮终有此一劫？！\n",
"一阵微风吹过，丐帮帮众唏哩哗啦全倒了下去，只有洪帮主摇摇晃晃地坚持着不倒，突然四面杀声震天，洪帮主奋力抵抗，但很快就淹没在铁骑当中。。。。。。\n",
"想到这里，你不禁打了个寒颤，再也不敢往下想了。\n",
"\n\n情势十万火急，看来只有犯险去刺杀赫连铁树啦！！！\n\n"
"想到这里，你感到全身的血液都似要沸腾了！\n"
});

void jjww(object me, int i);

void create()
{
	set("short", "树林");
	set("long", @LONG
一遍遮天闭日的树林，平时很少有人来这里。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"eastroad1",
]));
	set("outdoors", "xixia");

	setup();
}

int valid_leave(object who, string dir)
{
	if (who->query_temp("tieshu") == 2)
		who->delete_temp("tieshu");

	if (who->query_temp("tieshu") == 3) {
		who->set_temp("tieshu", 4);
		jjww(who, 0);
	}

	return ::valid_leave(who, dir);
}

void jjww(object me, int i)
{
	if (!me)	return;

	tell_object(me, HIR + str[i] + NOR);
	if (i+1 < sizeof(str))
		call_out("jjww", 2, me, i+1);
}
