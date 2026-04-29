// xilang.c 西厢走廊
// by Masterall
 
inherit "/u/l/lazypig/room/qiankuncave.c";
void create()
{
        set("short", "西厢走廊");
        set("long", @LONG
    你走在一条走廊上，东边是正门，北边是一座楼阁。
LONG
        );
 
        set("exits", ([
                "northup" : __DIR__"cangjingge",
                "east" : __DIR__"gate",]));
        set("blocks/northup","shangguan ren");
        set("objects",([
                 __DIR__"npc/shangguanren" : 1,
        ]));
        setup();
}

