// This is a room made by roommaker.
//by tlang

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"葫芦庙大殿");
	set("long", @LONG
	殿里供着几位神像，却都已经十分破旧了。一个老和尚坐在蒲团上闭
着眼睛，嘴里轻轻地念着什么。
LONG
);

	set("exits",([
	"south" : __DIR__"s_hlm",
	"north" : __DIR__"s_hlt",
	]));

	set("objects",([
	__DIR__"npc/s_xmei" : 1,
	]));

	setup();
	replace_program(ROOM);
}
