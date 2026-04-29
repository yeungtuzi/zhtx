// Room: /open/hihi/well.c
#include <ansi.h>
inherit ROOM;
int do_welldrop(object me, object obj);

void create()
{
	set("short", HIB"水井下"NOR);
	set("long", @LONG
这里是水井下，井水刚好齐腰深。因为离地面比较低，这里的光线十分
暗淡，你都根本看不清这里有什么东西。或许你可以用手摸摸(search)看。
LONG
	);
        set("exits",([
             "enter":  __DIR__"diaotong",
			]));
           set("no_magic",1);
	setup();
}
void init()
{       object ob;
	add_action("do_search","search");
	add_action("do_burn","burn");
	add_action("do_enter","enter");
        if( interactive( ob = this_player()))
        {
        remove_call_out("cooling");
        call_out("cooling", 1, ob);
        }
}
int do_give(object me)
{	object box,stone;
	if((int)query("marks/box")==1)
	message_vision(MAG"$N摸了半天，什么也没有摸到.\n"NOR,me);
	else {
	add("marks/box",1);
	box=new(__DIR__"obj/box");
	stone=new(__DIR__"obj/stone");
	message_vision(MAG"$N摸到一个东西，在黑暗之中也不知道是什么，好像是块石头，又像个小箱子.\n"NOR,me);
        if((int)me->query("marks/pixie1")==1 && query("marks/havebox")==1)
     {   box->move(me);
        me->set("marks/pixie1",0);
	me->set("marks/pixie2",1);
        return 1;  }
	else
	stone->move(me);
	return 1;}
}
int do_search(object me)
{	
	me=this_player();
	if( me->is_busy() ) 
		return notify_fail("你现在没有空！\n");

	message_vision("$N弯下腰，用手在井底摸起来。\n",me);
	me->start_busy(4);	
        call_out("do_give",4,me,0);
        
	return 1;
}
int cooling(object ob)

{
        int i,j,damage;
	 object *inv;        
	 object ob1;
	 object ob2;
         ob = this_player();
         inv=all_inventory(ob);
         for(j=0; j<sizeof(inv); j++)
                {        if((string)(inv[j]->query("id")) == "paper seal") {
                         destruct(inv[j]);
			  ob1=new(__DIR__"obj/badpaper");
			  ob1->move(ob);}
			else if((string)(inv[j]->query("id"))=="earth-warp sheet")
                        {destruct(inv[j]);
			 ob2=new(__DIR__"obj/badsheet");
			 ob2->move(ob);}}	
        if( environment(ob) == this_object())
        {
        message_vision(HIW"初春的井水冷得刺骨，泡在水里，$N不禁打了个哆嗦！", ob);
        message_vision("还是快点离开这里吧！！\n"NOR, ob);
        damage = random(20)+1;
        i =  (int)ob->query("kee");
        ob->set("kee",(int) i - damage);
        if( environment(ob) == this_object())
        call_out("cooling",random(5)+5, ob);    
        }

        return 1;
}

int do_enter()
{ 	int i;
        object *inv;
	object tong;
	tong = load_object(__DIR__"diaotong");
	inv=all_inventory(tong);
       for(i=0;i<sizeof(inv);i++) 
       if(userp(inv[i]))
 {	write( RED"小小的桶里已经挤了一个人了!!!\n"NOR); 
	return 1;}
	this_player()->move(tong);
	message_vision("$N钻进了吊桶.\n",this_player());
        return 1;
}

void reset()
{	set("marks/havebox",0);
	::reset();
}
