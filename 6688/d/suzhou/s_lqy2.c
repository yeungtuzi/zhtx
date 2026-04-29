// This is a room made by roommaker.
//by tlang

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", MAG"丽秋院"NOR);
	set("long", @LONG
	     这是苏州城中最最风流的地方，本地的，外地的有钱人，不管年老
的，还是年少的，都带着满袋子钱来这儿寻快活。据说这院子是韦小宝因为不满
年轻时他妈工作处老鸨的凶恶，自己立志开的。这儿一片温馨，红罗绿帐，让人
心动不已。
LONG
);
	set("exits",([
	"down" : __DIR__"s_lqy",
	]));
	set("objects",([
	__DIR__"npc/s_girl" : 1,
	]));
	set("no_fight",1);
	set("no_spells",1);
	setup();
	replace_program(ROOM);
}
