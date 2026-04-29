// /d/xizang/class/budala/station.c

inherit ROOM;
// need to use standard station setup
//inherit STATION;

void create()
{
        set("short", "拉萨驿");
        set("long", @LONG
这里是拉萨驿,来自中原的官方文书均送达此地,由达赖活佛签发的文
件也是从这里送出.平民百姓也可以交钱搭乘驿车.驿站北边的房子是供人
阅览坻报,获取新闻的地方,东边是宫前街的拐角, 沿青石板路往北即可到
达布达拉宫正门.
LONG
        );
        set("exits", ([
        "east" : __DIR__"corner",
       "north" : __DIR__"newsroom",
]));
        setup();
//        replace_program(ROOM);
}
