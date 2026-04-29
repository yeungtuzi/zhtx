// shibanlu3.c 石板路
// by Masterall
 
inherit ROOM;
void create()
{
        set("short", "石板路");
        set("long", @LONG
    你走在一条平整的石板路上，两旁种满了苍松，修篁森森，绿荫满地，除了风吹树
梢的呜呜声，听不到别的动静。北面是一条石板路。东西两边是最近刚刚从花紫会和峨
嵋派请来的两位高手，没有得到教主的允许你最好不要去惊扰他们。
LONG
        );
 
        set("exits", ([
                "north" : __DIR__"shibanlu2",
                "south" : __DIR__"qianting",
                "east" : __DIR__"keting5",
                "west" : __DIR__"keting6",
        ]));
        setup();
        replace_program(ROOM);
}
 

