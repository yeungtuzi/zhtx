// Room: /open/hihi/houyuan.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIW"后院"NOR);
	set("long", @LONG
你来到了林家后院。后院中种有几株丁香树，现在正值开花季节，满树的
丁香开的正热闹，一阵阵花香飘来，令人陶醉不已。院子中央的水井(well)看
上去好像没有经常用。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
	  "east" : __DIR__"guodao",
	  "north" : __DIR__"woshi1",
	  "west" : __DIR__"houmen",
	]));
	set("resource/water", 1);
	set("item_desc",([
		"well" :"一口水井，井中大概有半人高的水.水面离地面又有三四丈高。\n"+
			"井上有一个打水用的大轱辘(gulu)，轱辘上系着一个吊桶(diaotong)，但\n"+
			"吊桶上的绳子好像不是很结实.\n",
		"diaotong": "一个吊桶，看上去大小刚好可以蹲进(enter)一个人。\n",
		"吊桶": "一个吊桶，看上去大小刚好可以蹲进(enter)一个人。\n",
		"gulu":"一个大轱辘。你可以用它摇上摇下(yao)来打水。\n",
		"轱辘":"一个大轱辘。你可以用它摇上摇下(yao)来打水。\n",	
	]));	
	setup();
}

void init()
{ 	add_action("do_enter","enter");
	add_action("go_down","godown");
	add_action("do_yao","yao");
}

int do_yao(object me)
{
	int i,haveman=0;
        object *inv;
	object tong;
	tong = load_object(__DIR__"diaotong");
	inv=all_inventory(tong);
       for(i=0;i<sizeof(inv);i++) if(userp(inv[i])) haveman=1; 
	 if((int)query("marks/yao")==0) 
	{
	 if(haveman) {
	          message("vision","吊桶又被人摇了下来.\n",tong);
	          message_vision("$N把吊桶摇了下去.\n",this_player());
                  add("marks/yao",1);
                  tong->set("exits/out",__DIR__"well");
                  return 1;
		 }   
     	   else {
		  message_vision( "$N把轱辘上的吊桶摇了下去.\n",this_player());
	  	  add("marks/yao",1);
 		  tong->set("exits/out",__DIR__"well");
        	  return 1;
		}
	}
	else { 
		if(haveman)
               { 
		message("vision","吊桶被人摇了上去。\n",tong);
		message_vision("$N把吊桶摇了上来。\n\n"+MAG"哎呀....\n\n"NOR+
		RED"桶里还有个人!!!!\n"NOR,this_player());
		tong->set("exits/out",__DIR__"houyuan"); 
	        add("marks/yao",-1);
                return 1;
		}    
		else
		{ 
	         message_vision( "$N把轱辘上的吊桶摇了上来.\n",this_player());
                 add("marks/yao",-1);
                 tong->set("exits/out",__DIR__"houyuan"); 
		 return 1;
		 }

	    } 
}

int do_hurt(object me)
{	object room;
	room=load_object(__DIR__"diaotong");
        me=this_player();
	message_vision("$N双脚一跳，手抓吊绳跳进的吊桶里。\n",me);
        message_vision("由于重力的作用，吊桶开始加速向下坠去.\n",me);
        me->move(__DIR__"well");
	me->set("eff_kee",(int)me->query("eff_kee")/2+1);
	me->set("kee",(int)me->query("kee")/2+1);
	me->set("gin",(int)me->query("gin")/2+1);
	me->set("sen",(int)me->query("sen")/2+1);
	me->set("eff_sen",(int)me->query("eff_sen")/2+1);
	me->set("eff_gin",(int)me->query("eff_gin")/2+1);
	add("marks/yao",1);
	room->set("exits/out",__DIR__"well");
        message_vision(RED"$N从那么高的地方坠下来，摔$N好疼啊!!!\n"NOR,me);
	return 1;
}
int reach(object me)
{	me=this_player();
        me->move(__DIR__"well");
        message_vision("$N顺着绳子爬了下来。\n", me);
        return 1;
}
int go_down(object me)
{	
	me=this_player();
        if((int)query("marks/yao")==1){
        message_vision("$N双手抓着绳子慢慢地爬下去.\n",me);
       
        call_out("reach",4,me);
        
	return 1;}
	
}	
int do_enter(object me)
{ 	int i,haveman=0;
        object *inv;
	object tong;
	tong = load_object(__DIR__"diaotong");
	inv=all_inventory(tong);
       for(i=0;i<sizeof(inv);i++) if(userp(inv[i])) haveman=1; 
	if(haveman) return notify_fail(RED"小小的桶里已经挤了一个人了!!!\n"NOR); 
	me=this_player();
	if((int)query("marks/yao")==0)
        {       call_out("do_hurt",1,me,0);
		return 1;}
	else
        message_vision("吊桶已经放下去了，你愿意沿着绳子爬(godown)下去吗？\n",me);
	return 1;
}

