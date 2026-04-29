//by zephyr

#include <ansi.h>
inherit "/u/z/zephyr/sunflower/npc/advance_npc";
void create()
{
	int lvl,t;
	set("level",5);
	set_name("张雨弦", ({ "zhang yuxian","zhang"}) );
	set("long",BLU@LONG
张雨弦江湖从未闻其名，乃是一名隐士。
他长袍大袖，穿在清瘦的身子上显得仙风道骨。
LONG NOR
	 );
	set("percmd", "conjure shade sense");
	set("title","隐士");
	set("age", 80);
	//set advanced skills
	lvl=query("level");
	t=230+(6-lvl)*25;

	set_skill("taiji-shengong", t+random(10));
	set_skill("taiji-jian", t+random(10));
	set_skill("dodge", t+random(10));
	set_skill("parry", t+random(10));
	set_skill("sword",t+random(10));
	set_skill("force",t+random(10));
	set_skill("magic",t+random(10));
	set_skill("essencemagic",t+random(10));
	set_skill("baguabu",t+random(10));
	set_skill("spells",200+t+random(10));
	set_skill("necromancy",100);	
	set_skill("perception", t+random(10));


	map_skill("force","taiji-shengong");
	map_skill("sword","taiji-jian");
	map_skill("magic","essencemagic");
	map_skill("parry","taiji-jian");
	map_skill("dodge","baguabu");
	map_skill("move","baguabu");
	map_skill("spells","necromancy");


	setup();
	set("max_mana",5000);
	set("mana",10000);
	set("mana_factor",200);
	set("max_sen",3000);
	set("eff_sen",3000);
	set("sen",6000);
	set("max_gin",3000);
	set("eff_gin",3000);
	set("gin",6000);
	set("per", 50);

	carry_object("/obj/cloth/cloth")->wear();
	carry_object("/obj/weapon/sword")->wield();
	set("weapon_type","sword");
		
}                          

                             
int killed_enemy(object ob)
{
	command("hmm");
}                 

int chat()
{       
	object *enemys,victim;
	int i;
	
	//没魔法盾牌了
	if( !query_temp("manashield") && ((int)query("mana"))>1000 )
	command("cast manashield");			
	//法力不够了，补充一点点
	if( (query("mana")<1500) && (random(100)>70) ){
		message_vision(HIY"$N闭目凝神，用谷衣心法的内力运转了一次「灵神诀」...\n"
		"一股青气从$N身上散出，汇聚在$P的顶心，然後缓缓淡去。.\n"NOR,this_object());
		add("mana",500);
	}

	if( (query("sen")<500) && (random(100)>50) ){
		message_vision(HIC"一团青光围住$N的眉心，$N显得有精神多了\n"NOR,this_object());
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
