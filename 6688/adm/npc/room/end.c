// all is over!
#define __BAK_EXTENSION__  ".bak.o"

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", HIR"时空终点"NOR);
	set("long",GRN @DESC
恍惚之间你来到了这个以前从来没有见到过的地方，一切都
如此的陌生，一切又如此的熟悉。这里一定是前世你曾经待过的
地方，不管外面风云变幻，在这里，一切都已经静止，或许，这
就是每个人得到最终解脱的地方。看着如血残阳映着天际那一抹
晚霞，你突然明白了一切。
DESC 
+HIR"\n                   这里，就是终结。\n\n"+NOR+
GRN @DES 
      一切都不再有意义，一切，都结束了，无论恩怨情仇，
      花开花落，现在都到了结束的时候。


DES NOR    
	);
	setup();
	set("no_fly",1);
	set("no_magic",1);
	set("no_fight",1);          
	set("no_death",1);
}


void init()
{
	object me=this_player();
	add_action("do_quit","quit");	
	add_action("do_quit","summon");
	add_action("do_quit","pray");	
	add_action("do_quit","give");	
	add_action("do_quit","drop");
	add_action("do_quit","get");				
	add_action("do_quit","put");		
	add_action("do_quit","suicide");		
	
	if( !wiz_level(me) && !raw_wiz_level(me) )
	{
		me->start_busy(2000);
		me->set("env/invisibility",9);
		me->set("startroom",__FILE__);
		call_out("start_suicide",3,me);
	}

}	                                

int do_quit(string arg)
{
	write("一切，都不再有意义！\n");
	return 1;
}	         

int start_suicide(object me)
{
		tell_object( me,
			HIR "\n\n你的天年已尽，三分钟之后，我们就永别了。\n\n\n" NOR);
		me->set_temp("suicide_countdown", 90);
		me->start_busy( bind((: call_other, __FILE__, "slow_suicide" ,me:), me),bind((: call_other, __FILE__,"halt_suicide":),me));	
}	

int halt_suicide(object me, object who, string reason) 
{
	return 0;
}                


void review(object me,int i)
{
	string bye_msg,tmp;
	
	i  = 10 - i;
	if( i < 1 ) i = 1;
	if( i > 9 ) i = 9;
	switch(i)
	{
		case 1 : bye_msg = HIM"尽管早就已经有了预兆，但是真不敢相信自己也会和其\n他人一样，无法逃脱天命的束缚。";break;
		case 2 : bye_msg = HIC"虽然早就知道，每个人的这一天都迟早要到来，可是，\n当它当真发生在自己身上的时候，又多么希望这一切是虚幻的。";break;
		case 3 : bye_msg = HIM"回首你匆匆"+chinese_number(me->query("age"))+"年的人生岁月，无论是欢笑还是泪水，\n鲜血和汗水，爱情与仇恨，都已经离你如此之远。";break; 
                case 4 :
                	if(stringp(tmp=me->query("wife/name")) || stringp(tmp=me->query("husband/name")) )
                	{
                		bye_msg = HIG"你不禁想起了你的爱侣"+tmp+"，你们在一起的往事，一颦一笑，都仿佛历历在目。";
                	}
                	else
				bye_msg = HIG"你不禁想起了你人生匆匆，到头来却孑然一身，你是否为了成功放弃了太多本应珍惜的东西？";
			break;                	
		case 5 : 
			bye_msg = HIY"如果有时间能够倒流，能够重来一次，你会如何选择自己的人生之路？";break; 
		case 6 : bye_msg = HIR"这里的一切都是静止的，只有如血残阳挂在天际，四周死一样的沉寂，没有风，没有一丝生命的气息。";break; 
		case 7 : bye_msg = HIM"你是否还记得你最初开始的时光？那耗费在泥巴里面的无数光阴，那被耽搁了的很多事情？";break;
	        case 8 : bye_msg = HIG"花谢花开，潮落潮起，一切既然有开始，就必定有终结。";break;
	        case 9 : bye_msg = HIG"多多珍重吧，记得我们的祝福，记得学会去爱爱你的人。";break;		
        }
	tell_object(me, bye_msg +"\n"NOR);	
}	


int slow_suicide(object me)
{
	object link_ob;
	int stage,n,i;
	string *custom_ob,filename,id,first;
	
	stage = me->query_temp("suicide_countdown");
	me->add_temp("suicide_countdown", -1);
	if( stage > 1 ) {
		if( stage%10 == 0 )
			review(me,stage/10);	
		return 1;
	}

	link_ob = me->query_temp("link_ob");
	if( !link_ob ) return 0;

	log_file("static/SUICIDE",
		sprintf("%s finished his life on %s, at the age of %d\n", geteuid(me), ctime(time()),me->query("age")) );

	seteuid(getuid());
	cp( link_ob->query_save_file() + __SAVE_EXTENSION__ , "/databak/login");
	rm( link_ob->query_save_file() + __SAVE_EXTENSION__ );
	rm( link_ob->query_save_file() + __BAK_EXTENSION__ );
	cp( me->query_save_file() + __SAVE_EXTENSION__ , "/databak/user");
	rm( me->query_save_file() + __SAVE_EXTENSION__ );
	rm( me->query_save_file() + __BAK_EXTENSION__ );
	//删除信件
      id = getuid(me);
	cp( "/data/mail/"+id[0..0]+"/"+id+".o" , "/databak/mail" );
	rm( "/data/mail/"+id[0..0]+"/"+id+".o" );

	tell_object(me,"永别了，祝君多多珍重 :)。\n");
	tell_object(me,HIG
@DSS	

莫听穿林打叶声，何妨吟啸且徐行。
竹杖芒鞋轻胜马，谁怕？一蓑烟雨任平生。

料峭春风吹酒醒，微冷，山头斜照却相迎。
回首向来萧瑟处，归去，也无风雨也无晴。	

DSS NOR );
	message("shout", HIY"\n"+me->name()+"走完了匆匆"+chinese_number(me->query("age"))+"岁的人生历程，以后你再也看不到这个人了。\n"NOR, users(),({me}));
	destruct(me);
	return 0;
}



