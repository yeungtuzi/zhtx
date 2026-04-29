// /d/xizang/shop1.c

#include <room.h>

inherit ROOM;

void create()
{
        set("short", "商号后院");
        set("long", @LONG
这里是鹰记的后院.除了开设钱庄和当铺的业务以外,在精明的胡金袖建议下,卜
鹰的商号又成了镖局,承接保镖和货物押运(escort)的生意.胡金袖自任账房先生,托
货的,领镖的,回报(report)任务的,以及为了赚钱想加入(join)保镖行列的人来来往
往,把个宁静的小院弄得热闹非凡.因为很多货物送往遥远的中原,一时押运人力不够
用,只好把东北边两间屋子临时作了货仓,堆放了很多货箱.
LONG
        );
        set("exits", ([
                "west" : __DIR__"shop",
        ]));
	set("objects", ([
                __DIR__"npc/hujinxiu": 1 ]) );
	set("this_house", "鹰记商号");
	setup();
	replace_program(ROOM);
}
