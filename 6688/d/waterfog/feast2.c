// Room: /d/waterfog/fwese.c

inherit ROOM;

void create()
{
        set("short", "东侧厅");
        set("long", @LONG
这里是水烟阁东边的侧厅，东边隔著栏杆就是深不见底的深谷，从
这里向外眺望，更可以感受到水烟阁孤立於独峰之上，傲视群山的气魄
，这里有一道阶梯通往二楼，往北是厨房与储存杂物的仓库。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : "/d/waterfog/feast3",
  "south" : "/d/waterfog/feast1",
  "up" : "/d/waterfog/feup1",  
]));
        set("outdoors", "snow");
//        set("objects", ([
//             "/daemon/class/fighter/tiger":1,
//             "/daemon/class/fighter/guard":2
//             ]) );
   
        setup();
        replace_program(ROOM);
}
