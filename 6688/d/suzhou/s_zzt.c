// This is a room made by roommaker.
//by tlang

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", YEL"正厅"NOR);
	set("long", @LONG
	这儿与刚才的地方相比，真是让人惊讶不已。大厅正中供着三清神像，
前面摆满香蜡烛还有各色供品。旁边是一溜太师椅，上面铺着杭州出产的丝绸。
四面墙上挂满了各个朝代大家们的书画作品，而且都是真迹。东边有读书声传来。	
LONG
);
	set("exits",([
	"east" : __DIR__"s_zsf",
	"north" : __DIR__"s_zqt",
	"south" : __DIR__"s_zht",
	]));

	set("sleep_room",0);

	setup();
	replace_program(ROOM);
}
