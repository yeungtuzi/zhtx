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
	setup();
}
void init()
{       object ob;
	add_action("do_search","search");
	add_action("do_burn","burn");
	add_action("do_enter","enter");
 //       add_action("do_quit", "quit");
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
	if((int)me->query("marks/pixie")==1)
     {   box->move(me);
	me->set("marks/pixie",0);
	me->set("marks/pixie2",1);
        return 1;  }
	else
	stone->move(me);
	return 1;}
}
int do_search(object me)
{	
	me=this_player();
	message_vision("$N弯下腰，用手在井底摸起来。\n",me);
	
        call_out("do_give",4,me,0);
        
	return 1;
}
int cooling(object ob)

{
        int i;
        int damage;
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
/*
int do_quit(string arg)
{
        object me, *inv;
        int i, ti;
        me = this_player();
        inv = all_inventory(me);
        for(i=0; i<sizeof(inv); i++) 
        {
                do_welldrop(me, inv[i]);
        }
       remove_call_out("cooling");
       ti = time(); 
       while( time() - ti < 1 );
       "/cmds/usr/quit"->main(me, arg);
       return 1;
}

int do_welldrop(object me, object obj)
{
        mixed no_drop;
        if( no_drop = obj->query("no_drop") )
                return 0;
        if (obj->move(environment(me))) {
                if( obj->is_character() )
                        message_vision("$N将$n从背上放了下来，躺在地上。\n", me, obj);
                else {
                        message_vision( sprintf("$N丢下一%s$n。\n",     obj->query("unit")),
                                me, obj );
                        me->save();
                        if( !obj->query("value") && !obj->value() ) {
                                write("因为这样东西并不值钱，所以人们并不会注意到它的存在。\n");
                                destruct(obj);
                        }
                }
                return 1;
        }
        return 0;
}
int do_burn(object me)
{	me=this_player();
	message_vision(HIB"$N的符纸和所画的符咒被井水泡湿了，点不着!! "NOR+MAG" ^_*\n"NOR,me);
	return 1;
}
*/
int do_enter()
{ 	int i;
        object *inv;
	object tong;
	tong = load_object(__DIR__"diaotong");
	inv=all_inventory(tong);
       for(i=0;i<sizeof(inv);i++) 
       if(userp(inv[i])) return notify_fail(RED"小小的桶里已经挤了一个人了!!!\n"NOR); 
        return 1;         
}

