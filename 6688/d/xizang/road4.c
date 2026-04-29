// /d/xizang/road4.c

inherit ROOM;

void create()
{
        set("short", "雪梅洞口");
        set("long", @LONG
穿过梅林,你眼前是一个山洞的洞口,洞口边石壁上刻着"踏雪寻梅"四
个大字.
LONG
        );
        set("exits", ([
  "westup" : __DIR__"road3",
  "enter"  : __DIR__"shandong",
]));

        setup();
        replace_program(ROOM);
}
