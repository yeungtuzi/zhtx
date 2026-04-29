inherit ROOM;


void create()
{
   set("short", "内洞");
        set("long", @LONG
只见四面都是黑色的岩石，洞内黑沉沉的，靠近洞底的墙壁隐隐约约座着一名
老僧，但看不清面容，地上似乎还有一只檀木箱子。
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
    "out" :"/d/shaolin/damodong",
]));
    set("objects", ([
         "/class/shaolin/dmlzh" : 1,
    //   "/d/shaolin/obj/box" : 1, 
      
  ]) );
    
    /* set("item_desc", ([
                "木箱": "这个箱子烂得都不行了，一看便知年深久远\n",
                "box": "这个箱子烂得都不行了，一看便知年深久远\n",
           ]));*/  
    setup();    
        replace_program(ROOM);
}
