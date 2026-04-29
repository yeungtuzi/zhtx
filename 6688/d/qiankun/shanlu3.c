// shanlu3.c 山路
// by Masterall
 
inherit ROOM;
 
void create()
{
        set("short", "山路");
        set("long", @LONG
    你走在一条弯弯曲曲的山路上，据说再往前走就是乾坤教的地界了，乾坤教近些年
来在武林中势利逐渐强大起来，烧杀抢掠，无恶不作，连官府都为之头痛，你还是走的
远点好，小心落在他们手里丢了小命。
LONG
        );
         set("outdoors", "qiankun");
 
        set("exits", ([
                "westdown" : __DIR__"shanlu4",
                "northup" : __DIR__"shanlu2",
        ]));
        set("objects",([
                 __DIR__"npc/jiaotu" : 2,
         ]));
        setup();
        replace_program(ROOM);
} 
 

