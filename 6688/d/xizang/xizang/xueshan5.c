// /d/xizang/xueshan5.c

inherit ROOM;

void create()
{
        set("short", "山脚");
        set("long", @LONG
到了这里,气候已不似山上寒冷,但仍然远远冷过中原地方,天分外的蓝,阳
光强烈得刺眼,一条山路顺着山谷中较为平坦的地势向西延伸.
LONG
        );
        set("exits", ([
     "west"  : __DIR__"mroad",
   "eastup"  : __DIR__"xueshan4",
]));
        set("outdoors", "xizang");
        setup();
        replace_program(ROOM);
}
