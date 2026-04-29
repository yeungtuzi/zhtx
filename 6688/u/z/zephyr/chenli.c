//by zephyr

#include <ansi.h>
inherit NPC;
object me = this_object();
void create()
{
	set_name("陈羽立", ({ "chen yuli","chen","chen li"}) );
	set("long",WHT@LONG
陈羽立生于锦官城，年幼时机缘巧合拜到茅山派一隐居高人门下，是茅
山道术的唯一女传人。其师身世乃是江湖中一大秘密，与茅山、武当、
步玄、西藏大招寺等几大门派都有极大干系。
她武功修成之后，一直居住于成都城东的一处幽静的竹楼，不问江湖之
事。但三年前她受葵花宫宫主之邀，来到此处做了葵花宫玉琴楼护法。
乃是众护法中武功最神秘也最深不可测的一个，传说她的武功甚至在三
位武功绝顶的楼主之上。
她看上去二十一二岁年纪，肌肤胜雪，娇美无比，容色绝丽，让人不可
逼视。长发披肩，全身白衣，头发上束了条金带，阳光一映，更是灿然
生光。一身装束犹如仙女一般。
LONG NOR
	 );

	set("gender", "女性" );
	set("title",CYN"葵花宫"YEL"玉琴楼"NOR"护法");
	set("nickname",CYN"锦官玉女"NOR);
	set("age",25);
	//set advanced skills

	set_temp("manashield",1);	
	set("str", 100);
	set("int", 100);
	set("cor", 100);
	set("cps", 100);                       
	set("per", 100);
	set("con", 100);

	set("atman", 20000);
	set("max_atman", 10000);

	set("force", 20000);
	set("max_force", 10000);
	set("force_factor", 200);

	set("mana", 20000);
	set("max_mana", 10000);

          set("combat_exp", 10000000);

	set_skill("taiji-shengong", 400);
	set_skill("taiji-jian", 400);
	set_skill("dugu-jiujian", 400);
	set_skill("taiji-quan", 400);
	set_skill("dodge", 400);
	set_skill("parry", 400);
	set_skill("sword",400);
	set_skill("cuff",400);
	set_skill("force",400);
	set_skill("magic",400);
	set_skill("essencemagic",400);
	set_skill("mysterrier",400);
	set_skill("spells",400);
	set_skill("necromancy",400);	
	set_skill("perception", 400);
	set_skill("qimen-bagua", 400);

	set("chat_chance_combat", 80);
	set("chat_msg_combat", ({
 (: perform_action, "dodge.hasten" :),
 (: perform_action, "dodge.mirror" :),
	}) );

	map_skill("force","taiji-shengong");
	map_skill("cuff","taiji-quan");
	map_skill("sword","dugu-jiujian");
	map_skill("magic","essencemagic");
	map_skill("parry","taiji-jian");
	map_skill("dodge","mysterrier");
	map_skill("move","mysterrier");
	map_skill("spells","necromancy");

	prepare_skill("cuff","taiji-quan");

	setup();
	set("per", 100);

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
	if( (query("mana")<1000) && (random(100)>90) ){
		message_vision(BLU"$N闭目凝神，用谷衣心法的内力运转了一次「灵神诀」...\n"
		"一股青气从$N身上散出，汇聚在$P的顶心，然後缓缓淡去。.\n"NOR,this_object());
		add("mana",2000);
	}
	//招兵

	if( (query("sen")<1000) && (random(100)>50) ){
		message_vision(WHT"一团白色光围住$N的眉心，$N显得有精神多了\n"NOR,this_object());
		add("sen",50);
	}
	if( (query("gin")<1000) && (random(100)>50) ){
		message_vision(MAG"一团紫光围住$N的眉心，$N显得有精神多了\n"NOR,this_object());
		add("gin",50);
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
	
	if ( ( victim->query("gin")<800 ) && ( victim->query("max_mana")/2 < me->query("max_mana") ) && ( victim->query("mana")/2 < me->query("mana") ))
        { 
			evaluate((: cast_spell, "drainerbolt" :));
	}
	else if ( ( victim->query("max_mana")/2 < me->query("max_mana") )  && ( victim->query("mana")/2 < me->query("mana") ))
	{
			evaluate((: cast_spell, "netherbolt" :));
	}
	
	if( random(100)>90 ){
		command("cast invocation");
		command("hitdown " + victim->query("id"));
		command("say 你这不知深浅的" + RANK_D->query_rude(victim) + "，今日就让你晓得我的厉害");
	}

	return ::chat();
	
}	
