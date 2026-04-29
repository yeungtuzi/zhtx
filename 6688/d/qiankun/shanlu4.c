// shanlu4.c 山路
// by Masterall
 
inherit ROOM;
 
void create()
{
        set("short", "山路");
        set("long", @LONG
    从这里向西南方向走就是襄阳城了，由于离官府的管辖范围比较近，这里出没的乾
坤教徒会少点，但是最好还是赶紧离开这个是非之地，你心中一动，不由得加快了脚步
。
LONG
        );
         set("outdoors", "qiankun");
 
        set("exits", ([
                "southwest" : "/d/road/xiangyang",
                "northup" : __DIR__"shanlu3",
        ]));
        setup();
        replace_program(ROOM);
} 
 

