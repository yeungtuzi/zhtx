// Room: /d/heimuya/.c
// write by: dfbb@hero 
// date 97/01/25

inherit ROOM;

void create()
{
        set("short","广场");
        set("long", @LONG
一个大广场,全由汉白玉铺成,面积很大,一座非常宏伟的建筑
屹立在广场上,这就是日月神教的权力中心----"成德殿"了.
东西两侧是上任神教长老们闭关的地方，他们现在不问俗事，
潜心钻研武学，希望能有朝一日光大神教武学，压倒那些名门
正派。
LONG
        );

        set("exits", ([
                "north" :__DIR__"cdd",
                "south" :__DIR__"dingfeng11",
		"east"  :__DIR__"jiantang",
		"west"  :__DIR__"daotang",
                "northup"  :__DIR__"shenge",
        ]));
        set("objects",([
                __DIR__"npc/jiao_zhong7" : 4,
                __DIR__"npc/ghostme" : 1,
        ]));

        set("outdoors", "heimuya");
        setup();
        replace_program(ROOM);
}

