// liangting.c
//by emote

inherit ROOM;

void create()
{
        set("short", "凉亭");
        set("long", @LONG
行到近处，见人群之中有一座小小凉亭，那是旷野中供
行旅憩息之用，构筑颇为简陋。一群人围着凉亭，相距约有
数丈，却不逼近，只见亭中赫然有个白衣老者，孤身一人，
坐在一张板桌旁饮酒，他是否腰悬弯刀，一时无法见到。此
人虽然坐着，几乎仍有常人高矮。                       
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
		"southeast"  : "/d/road/luoyang",
]));
        
        set("objects", ([
                (__DIR__"npc/xiang"):1,
                (__DIR__"npc/jiao_zhong6"): 5,
                (__DIR__"npc/mdizi"):5,
                ]));
        setup();
        replace_program(ROOM);
}
