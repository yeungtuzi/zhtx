//anyeyouling.c
//by zephyr
#include <ansi.h>
inherit "/u/z/zephyr/sunflower/npc/advance_npc";
void create()
{
	int lvl,t;
	set("level",4);

	set_name(BLK"暗夜幽灵"NOR, ({ "you ling","youling"}) );
	set("long",BLK@LONG
他身上穿的什么衣服，长得什么样子，完全看不清楚！甚至，
你不敢肯定他穿着衣服，他是否长着面孔……整个形体都笼罩
在黑色的一团雾中，在这样的环境里面不仔细看根本感觉不
到他的存在。你觉得浑身发麻——这是个什么“东西”？
LONG NOR
	 );
	//加盾，看鬼
	set_temp("manashield",1);	
	set_temp("apply/astral_vision", 1);
	
	//set advanced skills
	lvl=query("level");
	t=230+(6-lvl)*25;
	set("percmd","conjure shade sense");
	set_skill("serpentforce", t+random(10));
	set_skill("spicyclaw", t+random(10));
	set_skill("claw",t+random(10));
	set_skill("force",t+random(10));
	set_skill("stormdance",t+random(10));
	set_skill("spells",300+t+random(10));
	set_skill("necromancy",99);	
	set_skill("perception", t+random(10));


	map_skill("force","serpentforce");
	map_skill("claw","spicyclaw");
	map_skill("parry","spicyclaw");
	map_skill("move","stormdance");
	map_skill("dodge","stormdance");
	map_skill("spells","necromancy");
	prepare_skill("claw", "spicyclaw");

	setup();
	set("chat_chance_combat",80);
        set("chat_msg_combat", ({
		(: command,"cast invocation" :),
		(: consider :),
        }) );


	set("sen",3000);
	set("eff_sen",3000);
	set("max_sen",3000);
	set("gin",3000);
	set("eff_gin",3000);
	set("max_gin",3000);
	set("max_mana",10000);
	set("mana",20000);
	set("max_atman",5000);
	set("atman",10000);
	set("mana_factor",300);    
	set("force_factor",300);    
	set("per",5);
	set("age",1000);
	set("kar",200);
	set("spi",100);
	carry_object("/obj/cloth/cloth")->wear();
}                          

                             
int killed_enemy(object ob)
{
	command("say 自己找死，惹到我的头上来了");
	command("heng");
}                 
                     
//幽灵的特异功能
int chat()
{       
	object *enemys,victim;
	int i;



	//没魔法盾牌了
	if( !query_temp("manashield") && ((int)query("mana"))>500 )
	command("cast manashield");			
	//法力不够了
	if( (query("mana") < 3000) && (random (100)>80) ){
		message_vision(HIB"$N凄厉的长叫一声,从它身后的地上窜出一道黑光,注入到它的顶门里.\n"NOR,this_object());
		add("mana",1000);
	}
	//神不够了
	if( (query("sen")<500) && (random(100)>90) ){
		message_vision(HIB"$N顶门闪过一道青光,显得有精神多了.\n"NOR,this_object());
		add("sen",50);
	}
	//别太累了
	if( random(100) > 90 || is_busy() ) return ::chat();
	
	clean_up_enemy();
	enemys = query_enemy();
	i = sizeof(enemys);
	//不和NPC之类的家伙战斗
	while(i--)
	{
		if( !userp(enemys[i]) )
		{
			remove_enemy(enemys[i]);
			enemys[i]->remove_enemy(this_object());
		}                                            
	}	
	//现在对手就只剩下玩家了.来判断一下策略
	clean_up_enemy();
	enemys = query_enemy();
	i = sizeof(enemys);
	if( !i ) return ::chat();
	
	//随机挑一个对手吧
	victim = enemys[random(i)];	
	
	if (victim->query("gin")<500)
        { 
			evaluate((: cast_spell, "drainerbolt" :));
	}
	else if (victim->query("sen")<500) 
	{ 
			evaluate((: cast_spell, "feeblebolt" :));
	}
	else
			evaluate((: cast_spell, "netherbolt" :));


	
	return ::chat();		
	
}	


void die()
{		
        if( environment() ) {
        message("sound", BLU"\n\n暗夜幽灵凄厉的发出一声惨叫！\n\n", environment());
        message("sound", BLK"\n暗夜幽灵身子一阵急剧的扭曲，身周的黑雾急剧的收缩了一下\n\n", environment());
        message("sound", HIR"\n砰————的一声，那团黑雾爆炸开来，"NOR + WHT"从中间窜出一道闪亮的银色光芒\n\n"NOR, environment());
        message("sound", HIW"\n只见此光象流星一样在半空打了个转，唰的一声钻到一棵古树脚下的地里消失不见了\n\n"NOR, environment());
		if (random (100) > 50)
			{
				object ob = new ("/u/z/zephyr/sunflower/treasure/kuihualing");
				ob->move(environment(this_object()));
				message("sound", WHT"\n借着那道亮光，你发现一棵古树旁边的灌木丛里仿佛有什么东西在闪光。你定睛一看，居然是一块精致的小木牌。\n\n"NOR, environment());
			}
		}
		::die();
}
