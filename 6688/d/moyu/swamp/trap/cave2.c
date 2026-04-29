// trap1.c
// by meteoric
#include "ansi.h"
inherit "/ldg/std/doom.c";

void create()
{
	set("short", "山洞");
	set("long", BLK@LONG
黑突突的洞里死寂一片，只有听似钟孔石滴落的岩水微响。你试探的“啊”了一声。
丙然在这深不可测的洞穴，传来了：“啊啊啊啊……”无数声，声音既被歪曲，而且
诡秘异常。听来这石洞似有九曲十三弯，通道不少。隐约的天光下，石壁青蓝一片，
很是可怖。
LONG NOR);
	set("exits", ([ /* sizeof() == 2 */
	  "west": __DIR__"cave1",
	  "north":__DIR__"cave3",
	]));
	setup();
}