//shufang.c 书房
//by emote
inherit ROOM;

void create()
{
	object shelf,ob;
	set("short","书房");
	set("long",
@LONG
这是岳不群的书房，平时岳不群就在这里会见客人。书房里面有好几排
书架，书架上摆满了书。
LONG);
        set("exits", ([ /* sizeof() == 2 */
		"east"  : __DIR__"zhengqitang",
]));
        set("objects", ([
                 __DIR__"obj/shelf":1,
				 
]));
		setup();
        shelf=present("shelf",this_object());
        switch( random(6) ) {
                case 0:
                        ob=new(__DIR__"obj/book-zixia");
                        ob->move(shelf);
                        break;
                case 1:
                       ob=new(__DIR__"obj/book-dodge");
                        ob->move(shelf);
                        break;
                case 2:
                       ob=new(__DIR__"obj/book-purple");
                        ob->move(shelf);
                        break;
                case 3:
                       ob=new(__DIR__"obj/book-force");
                        ob->move(shelf);
                        break;
                case 4:
                       ob=new(__DIR__"obj/book-sword");
                        ob->move(shelf);
                        break;
                case 5:
                       ob=new(__DIR__"obj/book-parry");
	                   ob->move(shelf);
                        break;
                }


}

