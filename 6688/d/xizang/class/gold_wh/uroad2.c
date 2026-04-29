// /d/xizang/class/gold_wh/uroad2.c

inherit ROOM;

void create()
{
        set("short", "山路");
        set("long", @LONG
这里是一条荒草迷漫的小路,往南延伸到西藏草原，北边据说通往昆仑山.西
边是密宗金轮派札什伦布寺的大门.札什伦布是喇嘛教的大寺,主持金轮法王刚去
京城朝见天子回来不久.因他佛法精深,对答如流,天子龙颜大悦,御笔亲赐国师封
号给他.为此达赖喇嘛,班禅大师及雪山寺主持鸠摩智上人均觉不满.
LONG
        );
        set("exits", ([
                "northup" : __DIR__"uroad3",
              "southdown" : __DIR__"uroad1",
		   "west" : __DIR__"gate",
]));
        set("outdoors", "xizang");

        setup();
	replace_program(ROOM);
}
