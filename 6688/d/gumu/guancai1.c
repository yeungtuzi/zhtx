more guancai1.c
inherit ROOM;




void create()
{
 set("short", "棺材");
 set("long", @LONG
这是一口不大不小的棺材，好象没什么特别。
LONG
 );

 set("exits", ([
 "out" : __DIR__"gumu",
 ]));

setup();
}
> 