// Room: /u/p/pock/bj/fang3.c
#include <ansi.h>
#include <localtime.h>
inherit ROOM;

string *greeting_msg = ({     
	YEL"就在此时，忽听得门外一人走近，朗声道：“桂公公，你睡了没有？” \n"NOR,
	YEL"你说道：“睡了，是哪一位？有事明天再说罢。”\n"NOR,
	YEL"门外那人道：“下官瑞栋。”\n"NOR,
	YEL"瑞栋道：“下官有件急事，想跟公公商量。 \n\n"+
	   "瑞栋用手一推虚掩的门，走了进来。\n\n"NOR,
	YEL"瑞栋道：“适才奉太后懿旨，说今晚有刺客闯宫犯驾，大逆不道，命我相桂公公查问明白。”\n"NOR,
	YEL"你心中一惊，心想：去见太后可不妙，骗他去见皇上才好。\n"+
	   "你说道：“是啊，适才皇上问起是谁勾引刺客进宫的。他说这么多天怎么不见瑞副总管保驾？”\n"NOR,
	YEL"瑞栋大怒道：“太后说你最能胡说八道，果然没错。你跟我去见太后罢。”\n"NOR,
	YEL"瑞栋道：“太后又说，如果你不肯跟我走，就是心中有鬼，命我格杀勿论。很好，拿命来。\n"NOR,
	});
void create()
{	object box,ob1;
	set("short", HIM"小房"NOR);
	set("long", @LONG
这是御膳监居住的地方。进门的右边，放着一个大水缸，也不知道里边装的
是什么。水缸边上靠窗户的地方，一个小桌子靠墙摆在那里。桌子旁边并排放着
两口箱子。一道屏风把整个房子分成两部分，里边摆着一大一小两张床。除此以
外，这个房子就再也找不到别的起眼的东西了。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
		"east" : __DIR__"fang2",
		]));
	set("objects",([
		__DIR__"npc/haidafu":1,
		__DIR__"npc/xiaoguiz":1,
		__DIR__"obj/box":1,
	       ]));
	setup();
	box=present("box",this_object());
	if(random(3))
		 ob1=new(__DIR__"obj/pitiao");
	 else
                ob1=new("/obj/toy/dust");
         ob1->move(box);

}
void reset()
{	int t;
	mixed *local;
        local = localtime(time()*6);
        t = local[2] * 60 + local[1]; 
	if( t>300&&t<600) 
        call_out("msg",1);
	::reset();
}	
int msg()
{	object who,room1;
        object *inv;
	int i;
	who=this_player();
	room1=this_object();
	inv=all_inventory(room1);
        for(i=0;i<sizeof(inv);i++) if(userp(inv[i])) 
          {  	call_out("removenpc",1);
		tell_object(who, greeting_msg[0]);
		call_out("secondmsg",5);
		call_out("thirdmsg",10);
		call_out("forthmsg",15);
		call_out("fifthmsg",20);
		call_out("sixthmsg",25);
		call_out("seventhmsg",30);
		call_out("lastmsg",35);
	  }   
	return 1;
}
int secondmsg()
{          tell_object(this_object(),greeting_msg[1]);
	   return 1;
}
int thirdmsg()
{          tell_object(this_object(),greeting_msg[2]);
	   return 1;
}   
int forthmsg()
{
        tell_object(this_object(),greeting_msg[3]);
        return 1;
	
}
int fifthdmsg()
{          tell_object(this_object(),greeting_msg[4]);
	   return 1;
}  
int sixthmsg()
{          tell_object(this_object(),greeting_msg[5]);
	   return 1;
}  
int seventhmsg()
{          tell_object(this_object(),greeting_msg[6]);
	   return 1;
}  
int lastmsg()
{	object ob;	
	tell_object(this_object(),greeting_msg[7]);
	ob=new(__DIR__"npc/ruidong");
	ob->move(this_object());   	
}
        
void removenpc()
{	object who,room1;
        object *inv;
	int j;
	string name;
	who=this_player();
	room1=this_object();
	inv=all_inventory(room1);
	for(j=0;j<sizeof(inv);j++)
	{ name=inv[j]->query("id");
	 if(name=="xiao guizi" || name=="hai dafu" )
	 destruct(inv[j]);
	}
}		
