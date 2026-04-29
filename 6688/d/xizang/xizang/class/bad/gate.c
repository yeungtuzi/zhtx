// /d/xizang/class/bad/gate.c

#include <ansi.h>
inherit ROOM;

string* name_list = ({
	"apul",
	"nstar",
	"meat",
	"mmud",
	"jake",
	"hic",
	"meteoric",
	"huny"
});
// here is the file name list for the good guys

void create()
{
        set("short", "谷口");
	set("long", @LONG
这里就是传说中有去无回的恶人谷,很难相信它竟是个暖风轻拂,鲜花盛开的
人间仙境.北边一条弯弯曲曲的小径通往群山中,西边有座简朴但是十分整齐干净
的草庐,东边就是谷内了,一块大石(rock)立在路边,上书"恶人谷"三个血红大字.
LONG
);
	set("item_desc", ([
		"rock" : "大石一角还有四个小字:["+HIR+"擅入者死"+NOR+"]\n",
	]));

	set("exits", ([
		"north" : __DIR__"path1",
		 "west" : __DIR__"grass_h",
		 "east" : __DIR__"enter",
	]));
	set("outdoors", "xizang");
	setup();
//        replace_program(ROOM);
}

void reset()
{
//set random appearing of the good guys
//3 out of total 8 each reset

	int i, j, k;
        i = random(sizeof(name_list));
        j = i + 1;
        if (j >= 7) j=0;
        k = j + 1;
        if (k >= 7) k=0;
        set("objects", ([
        __DIR__"npc/"+name_list[i] : 1,
        __DIR__"npc/"+name_list[j] : 1,
        __DIR__"npc/"+name_list[k] : 1,
        ]));	
	::reset();
}
