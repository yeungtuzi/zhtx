// room: mudao.c
// Jay 4/8/96
#include <room.h>
#include <ansi.h>

inherit ROOM;
int do_ban(string);

void create()
{
    set("name","江湖传言");
    set("id","duan longshi");
    set("short", "墓道");
    set("long", @LONG
     这是一条窄窄的墓道，北边通向古墓深处，南边已到
了尽头。南边尽头处有一个巨石，据说叫断龙石，石头有点松
动，旁边有块圆形的小石头，不知是不是可以拔出来(pull)。
地上满是大大小小的石头，有人从这里经常出入。
  
LONG
    );

    set("exits", ([
       "north" : __DIR__"mudao2",
       "south" :  __DIR__"duanlongshi",
    ]));

    set("item_desc", ([
      "stone" : "这是一个巨大的石头，比较光滑，搬搬试试(ban)。\n",
    ]) );
    setup();
}

void init()
{
    object book, me;
    me = this_player();
    add_action("do_ban", "pull");
   
}

int do_ban(string arg)
{
    int n;object me=this_player();
    n = this_player()->query("force");
    if( !arg || arg!="stone"){
        write("不要随便搬别人的东西！\n");
        return 1;
    }

    if( n < 500 || this_player()->query("max_force")<500)
    {
    	message_vision(
	    "$N走到石头前，使出吃奶的力气，使劲拔了几下石头，结果累了个半死...\n", this_player());	
	this_player()->set("force",0);
	this_player()->unconcious();
       return 1;
	
    }	
    
    message_vision(
    "$N走到石头前，将圆形的小石头拔了起来，只见流沙从洞中不停流出...\n", this_player());

    this_player()->start_busy(30);
    call_out("close",2,environment(me));        
    return 1;
}

void close(object room)
{
    object er;
    
    message("vision","断龙石轰然一声落了下来，封住了洞口。出路断绝了。\n", room);
    room->delete("exits/south");
    load_object("/d/gumu/duanlongshi");
    er = find_object("/d/gumu/duanlongshi");
    if( objectp(er) )             
    {
    	tell_room(er,"断龙石轰然一声落了下来，封住了洞口。出路断绝了。\n");
    	er->delete("exits/north");
    }
    if( this_player()->query_skill("yunu-xinfa",1) < 150 && this_player()->query_skill("qimen-bagua",1) < 150 )
    {
    	message_vision(
	    HIR"$N闪避不及，被断龙石砸个正准，只见$N如同一滩烂泥一样被压在了石头下面...\n"NOR, this_player());	
	this_object()->set("channel_id","江湖传言(Rumor)");
	CHANNEL_D->do_channel(this_object(),"rumor",this_player()->name()+"中了断龙石机关埋伏，一命呜呼了。\n");
	COMBAT_D->announce(this_player(), "dead");
	this_player()->die(1);
    }	               
}


