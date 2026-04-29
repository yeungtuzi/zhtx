// Room: /u/p/pock/bj/qqgong.c
#include <ansi.h>
#include <room.h>
#include <localtime.h>
inherit ROOM;
string *leave_msg = ({     
	CYN"$N正要往北离开时，忽然听得一个男人的声音从屋里传来。你觉得很奇怪，太后\n"+
	   "的屋子里怎么会有男人呢？于是捏手捏脚，走到窗前偷听起来。\n"NOR,
	CYN"只听得太后道：“阿燕武功高他十倍，人又机警，步步提防，哪会有事？”\n"NOR,
	CYN"那男人道：“能取得经书，自然最好，否则的话，哼哼！”\n"NOR,
	CYN"太后道：“你知道我已尽力而为了，我这样的身份，总不能押着个小太监在宫中走来走去。” \n"NOR,
	CYN"那男人道：“遇到这等大事，还管什么？”\n"NOR,
	CYN"过了半刻，那男人道：“不等了，我去瞧瞧。”\n"NOR,
	CYN"太后道：“你等一等，我和你同去。”走到床前，掀开被褥，又揭起一块木板来，\n"+
	   "烛光下青光一闪，手中已多了一枚短剑，插入剑鞘，别在腰间。\n"NOR,
	CYN"只见太后和那人走出寝殿，也不吹灭蜡烛，虚掩殿门，出了乾清宫。\n"NOR,
	});
string *second_msg = ({
	CYN"只听到一个女子声音道：“妈，我跟你办成了这件事，你赏我什么啊？”正是建宁公主。\n"NOR,
	CYN"听得太后道：“妈差你做件小事，也要讨赏，真不像话。”\n"NOR,
	CYN"建宁公主道：“啊呀，这还是小事吗？倘若皇帝哥哥查起来，知道是我拿了，\n"+
	   "非大大生气不可。”\n"NOR,
	CYN"太后道：“一部佛经，又有什么大不了的？” \n"NOR,
	CYN"建宁公主道：“既然没有什么大不了的，那我去跟皇帝哥哥说，你差我拿了这本\n"+
	   "』四十二章经『。”\n"NOR,
	CYN"太后道：“你去说好了，皇帝如来问我，我可不知道这回事。小孩子家胡言乱言，\n"+
	    "也作得准的？”\n"NOR,
	CYN"建宁公主叫道：“啊哟，妈，你想赖么？经书明明在这里。”\n"NOR,
	CYN"太后嗤的一笑，道：“那也容易，我丢在炉子里烧了便是。”\n"NOR,
	CYN"公主笑道：“算了，算了。我总说不过你，我回去睡觉了。”\n"NOR,
	});
void create()
{
	set("short", HIM"乾清宫"NOR);
	set("long", @LONG
乾清宫是太后的居住地。门庭前两边各有一个石雕灵龟，灵龟外又各有一个
石雕仙鹤。右边一排四个房子是服侍太后的宫女卧寝。北边中间的大房子则是太
后的寝宫。太后的一切起居饮食都可以在这里完成。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
		"north" : __DIR__"fang4",
		"east" : __DIR__"qqmen",
		]));
	create_door("east","乾清门","west",DOOR_CLOSED);
	setup();

}
int valid_leave(object me, string dir)
{	int t;
	object ob;
	mixed *local;
	ob=this_object();
        local = localtime(time()*6);
        t = local[2] * 60 + local[1];
	if(!query("happened")&&dir=="north")
	{
	 if(me->query_temp("meettao")&&present("jiunan shitai",ob)&&
		present("tao hongying",ob))
	 {       call_out("secondmsg",1,ob);
		 set("happened",1);
		 me->start_busy(5);
		 return notify_fail("");
	 }
	else 
	if( t>600&&t<900) 
	 {        call_out("msg",1,ob);
		  set("happened",1);
		  me->start_busy(5);
                  return notify_fail("");		  
	 }
	}
        return ::valid_leave(me, dir);    
}
void msg(object who,int stage)
{       who=this_player();
	 message_vision(leave_msg[stage],who);
	if( ++stage < sizeof(leave_msg) ) 
	 {
	  call_out( "msg", 3, who, stage );
	 }
	else call_out("removenpc",1);
}
void secondmsg(object who,int stage)
{	 object room,queen;
          who=this_player();
	  message_vision(second_msg[stage],who);
	if(!stage)
	     call_out("removenpc",1);
	if( ++stage < sizeof(second_msg) ) 
	 {
	  call_out( "secondmsg", 3, who, stage );
	 }
	else {
	     who->set_temp("meettao",0);
	     who->set_temp("meetmao",1);
	     queen=new(__DIR__"npc/fakequeen2");
	     room=load_object(__DIR__"fang4");
	     queen->move(room);
	}
	     
}
void removenpc()
{	object room1;
        object *inv;
	int j;
	string name;
	room1=load_object(__DIR__"fang4");
	room1->set("nobook3",0);
	inv=all_inventory(room1);
	for(j=0;j<sizeof(inv);j++)
	{ name=inv[j]->query("id");
	 if(name=="qing queen" || name=="rui chu" )
	 destruct(inv[j]);
	}
}		
