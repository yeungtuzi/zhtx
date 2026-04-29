// master.c
#include <ansi.h>

inherit "/u/z/zephyr/revengenpc.c";
inherit F_MASTER;
inherit F_QUEST;
inherit "/feature/challenge";

int ask_sheng_si_fu();
int ask_dodge();
int do_swear(string arg);
int ask_lingboweibu();

void create()
{
	set_name("天山童姥", ({ "tianshan tonglao", "tonglao", "master" }) );
	set("nickname", "唯我独尊");
	set("gender", "女性" );
	set("age", 96);
	set("str", 50);
	set("cor", 30);
	set("cps", 30);
	set("int", 30);
	set("per", 12);
	set("con", 20);
	set("kar", 20);
	set("max_force", 3500);
	set("force", 5000);
	set("force_factor", 150);
        set("max_mana", 800);
        set("mana", 800);
        set("max_atman",800);
        set("atman",800);
	set("long",
		"这难道就是令江湖中人闻风丧胆的灵鹫宫主人天山童姥？\n"
		"她看起来只有孩童般的身材，可是年纪一定很老了。\n"
		"她脸上充满唳气，神色傲然，令人不快。唯有双目如电，\n"
		"令人不寒而噤。\n"
	);
	create_family("灵鹫宫", 2, "尊主");
	set("family/create_time",4);
    	set("combat_exp", 5000000);
	set("shen_type", -1);
    	set("score", -20000);
		
        set("chat_chance_combat", 40);
        set("chat_msg_combat", ({ 
		(: exert_function,"recover":),
		(: exert_function,"powerup" :),
	 }) );

    	set_skill("parry", 200);
	set_skill("dodge", 180);
	set_skill("sword", 100);
	set_skill("throwing", 100);
    	set_skill("force", 200);
	set_skill("hand", 200);
	set_skill("strike", 200);
    	set_skill("literate", 150);
	set_skill("perception",100);

    	set_skill("bahuang-gong", 200);
    	set_skill("zhemei-shou", 200);
	set_skill("liuyang-zhang", 200);

	map_skill("force", "bahuang-gong");
	map_skill("parry", "liuyang-zhang");
	map_skill("strike", "liuyang-zhang");
	map_skill("hand", "zhemei-shou");

	prepare_skill("hand", "zhemei-shou");
	prepare_skill("strike", "liuyang-zhang");

	set("inquiry", ([
		"生死符" : (: ask_sheng_si_fu :),
		"轻功" : (: ask_dodge :),
		"凌波微步" : (: ask_lingboweibu :),
	]));
	setup();
	carry_object(__DIR__"k_cloth")->wear();
	carry_object(__DIR__"pipe");
  	carry_object(__DIR__"wan9");
  	carry_object(__DIR__"fake_wan9");
}
   
void attempt_apprentice(object ob)
{
	string name,new_name;

	if( ob->query("gender") != "女性") 
  	{     
		command("say 我灵鹫宫只收留孤苦伶仃的女子," + 
			RANK_D->query_respect(ob) + "还是回家享清福去吧！");
	       	return; 
	}
	if( ob->query("family/family_name") != "灵鹫宫" ){
		command("say 我只收灵鹫宫的人为弟子。\n");
		return;
	}
	if( ob->query_skill("bahuang-gong", 1) < 60 ){
		command("say 你是否还要在内功方面多下点功夫？");
		return;
	}
	command("smile");
	command("say 很好，只要你对姥姥忠心，以后好处是少不了的。");
	command("recruit " + ob->query("id") );
}
 
int ask_sheng_si_fu()
{
	object me, ob;

	me = this_player();
	ob = this_object();

	if( me->query("faith") < 1500 + me->query("betrayer") * 20000){
		command("say 生死符乃本门绝学，你先多为本门做贡献，日后我自然传你。");
		return 1;
	}

	if( me->query_skill("liuyang-zhang", 1) < 120 
	|| me->query_skill("force") < 180
	|| me->query("max_force") < 1200){
		command("say 你的功力不够。学了没得辱没了生死符的名声。\n");
		return 1;
	}

	command("say 你要想学姥姥的生死符绝技，必须答应我一个条件。未经姥姥允许，不得私自替外派弟子解除生死符！");	
	command("say 你且先立下一个重誓(swear)。");
	me->set_temp("ask_sheng_si", 1);
	return 1;
}

int do_swear(string arg)
{
	object me = this_player();

	if( me->query_temp("ask_sheng_si") != 1 )
		return notify_fail("在这里嚷什么嚷！\n");
	if( me->query("skill_mark/sheng_si_fu") )
		return notify_fail("不是和你说了吗？\n");
	message_vision("$N发誓道：“我"+me->query("name")+ "对天发誓，未经姥姥允许，决不私自替外派弟子解除已种生死符，如违此誓，叫我服下腐骨散筋丸，全身关节寸寸断节，尝尽人间千般苦楚而死！”\n", me);
	command("pat "+me->query("id"));
	command("say 很好，姥姥就传你这招生死符的绝技。\n");
	command("whisper "+me->query("id")+" 生死符乃是以掌上所凝成的薄冰，化为暗器，攻入敌人体内穴道。\n");
	tell_object(me, CYN"接着童姥又和详细解释如何逆运真气、如何凝气为冰，如何发射生死符，又如何运真气驱除生死符，种种手法，变化繁复。\n"NOR);
	command("say 这生死符千变万化，运用之妙，存乎一心，你须谨记在心。");
	me->set("skill_mark/sheng_si_fu", 1);
	me->delete_temp("ask_sheng_si");
	tell_object(me, "你学会了生死符的手法！\n");
	return 1;
}

int ask_dodge()
{
	object ob;

	ob = this_player();
	if( ob->query("family/master_id") != "tianshan tonglao" ) return 1;

	command("say 姥姥教你的功夫，一招就灭了对手，还要轻功干什么？\n");
	command("say 不过本派的凌波微步可是天下一等一的轻功！\n");
	return 1;
}

int ask_lingboweibu()
{
	object ob;
	
	ob = this_player();
	if( ob->query("family/master_id") != "tianshan tonglao" ) return 1;

	if( ob->query("faith") < 1500 || ob->query("betrayer"))
		return notify_fail("这些事以后再和你说吧！\n");
	
	if( ob->query("mark/tong_chushi") )
		return notify_fail("不是和你说了吗？\n");

	command("say 本派名叫逍遥派，当年我师父先后收下三个徒弟，一个是我，一个是你师叔无崖子，还有一个贱人。三人所学武功各不相同。");
	message_vision("童姥说到贱人二字时，说得咬牙切齿，恨恨不已。\n", ob);
	command("say 你师叔无崖子，后来做了逍遥派的掌门人，唉，这些事都是四五十年前的事了！");
	command("say 几十年没见到过你师叔了，也不知道现在在哪里？");
	command("say 这里有一封信，你找到他之后，把这封信交给他，他教不教你凌波微步，就看你的运气啦！");
	message_vision("童姥说完这些话，叹了口气，眼望远方，似有所思。\n", ob);
	tell_object(ob, "你平生第一次见到童姥叹气！\n");
	new(__DIR__"letter")->move(ob);
	ob->set("mark/tong_chushi", 1);
	return 1;
}
 
void init()
{ 	
	::init();
	add_action("give_quest", "quest");
  	add_action("do_swear","swear");
}
