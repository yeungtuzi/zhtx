// Room: /open/hihi/jianchi.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", MAG"摘剑池"NOR);
	set("long", @LONG
青城派在武林之中已经不是一年半月的事了，它的先辈曾经为之付出了
很大的努力。而青城又以剑法见长，武林中人为了表示对它的尊敬，在此立
了一个大石碑(sign),并规定凡是武林人物， 到此必须放下武器。由此也可
以看出当初青城派的兴盛。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
	  "west" : __DIR__"shijie",
	  "north" : __DIR__"shanmen",
	]));
        set("item_desc",([
           "sign":RED"                            佩\n"
                  "                            带\n"
                  "                            兵\n"
                  "                            器\n"
                  "                            者\n"
                  "                            不\n"
                  "                            得\n"
                  "                            入\n"
                  "                            内\n" NOR,
                ]));
        set("objects",([
           __DIR__"npc/renjie":1,
              ]));
        set("no_fight",1);
	setup();
	replace_program(ROOM);
}
