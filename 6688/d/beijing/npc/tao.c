// taohongying.c
#include <ansi.h>
inherit NPC;
string *leave_msg = ({     
	YEL"九难师太忽然说：“有人来啦！” \n"NOR,
	YEL"你一拉九难师太的手，躲在一口大瓦缸后。\n"NOR,
	YEL"只听得脚步声细碎，一人奔将过来，站定身四下一看，见到插在石堆上的木条，微微一怔。\n"+
	   "便走过去拔起来。\n"NOR,
	YEL"这人一转身，月光照在脸上，正是陶红英。 \n"NOR,
	YEL"九难师太和你从瓦缸后边走了出来。九难师太低声说道：“红英，你。。。你还认得我么？”\n"NOR,
	YEL"陶红英没有想到瓦缸后边还有人，吃了一惊，退后三步，右手在腰见一模，拔短剑在手，\n"+
	   "问道：“是。。。是谁？”\n"NOR,
	YEL"九难师太叹了口气，道：“原来你已不认得我了。”\n"NOR,
	YEL"陶红英道：“我。。。我见不到你的脸。你。。。你是。。。”\n"NOR,
	YEL"九难师太身子微侧，让月光照在蹋的半边脸上，低声道：“你相貌也变了很多啦。”\n"NOR,
	YEL"陶红英颤着声：“公主，是你？我。。。我。。。”扑过去抱住九难师太的腿。\n"+
	   "呜噎着伏在地上。\n"NOR,
	YEL"九难师太凄然一笑，在月光下，她脸上泪珠莹然。这一笑更显得凄清。\n"NOR,
	YEL"九难师太说：“你跟我出宫去吧！”\n"NOR,
	YEL"陶红英道：“是！公主，我以后要跟着你了。”又道：“公主那么好的\n"+
	   "武功，要是能把鞑子太后拿住，逼她交出经书，便可破了鞑子的龙脉。”\n"NOR,
	YEL"九难师太道：“什么经书？鞑子的龙脉？”陶红英于是把四十二章经的\n"+
	   "的来历简单介绍了一下。\n"NOR,
	YEL"九难师太默默的听完，沉吟半刻，道：“若能破了鞑子的龙脉，则最好\n"+
	   "不过了。走，我们这就走。”\n"NOR,
	});
void create()
{
	set_name("陶红英", ({ "tao hongying","hongying" }) );
	set("gender", "女性" );
	set("age", 43);
	set("title",HIC"宫女"NOR);
	set("long", @TEXT
陶红英早年入宫，曾经服侍过晚明的长公主。
TEXT
	);
	set("combat_exp", 1000000);

        set("str", 24);
        set("con", 28);
        set("int", 27);
	set("shen_type", 1);

        set("attitude", "friendly");
        set_skill("dodge", 150);
	set_skill("unarmed",150);
	set_skill("parry", 100);
        set_skill("force", 100);
        set_temp("apply/attack", 40);
        set_temp("apply/defense", 80);
	setup();
        add_money("silver", random(10));
        carry_object(__DIR__"obj/girlcloth")->wear();
}

void greeting(object who)
{	
	who->start_busy(2);
	call_out("msg",4,who);
	this_object()->set("happened",1);
	
}
void msg(object who,int stage)
{        say(leave_msg[stage]);
	if( ++stage < sizeof(leave_msg) ) 
	 {
	  call_out( "msg", 3, who, stage );
	 }
	else call_out("goqqgong",1,who);
}

void init()
{
	object ob;
	ob=this_player();
	::init();
	if(!query("happened"))
	{
	remove_call_out("greeting");
	call_out("greeting", 1, ob);
	}
}
int goqqgong(object who)
{
       command("say 我们走吧！到乾清宫去。");
	who->set_temp("meettao",1);
	set_leader(who);
}
	
