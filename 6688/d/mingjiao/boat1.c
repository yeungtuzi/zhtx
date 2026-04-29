inherit ROOM;

void create()
{
        set("short", "旧炮船");
        set("long", @LONG
	这是一艘十分威风的炮舰，只是大炮上覆盖着渔网，好象是旧了不用的炮舰
改来捕鱼。
LONG
        );
        set("objects",([
		__DIR__"npc/chuanlaoda1.c" : 1,
	]) );
        setup();
}


