// ning.c 宁中则
#include <ansi.h>
inherit F_MASTER;
inherit NPC;

int ask_xueyi();

void create()
{
        set_name("宁中则",({"ning zhongze","ning"}));
        set("nickname", HIC "华山玉女" NOR);
        set("title",GRN "华山派" NOR + YEL "第十八代" NOR+ GRN "掌门夫人" NOR);
        set("long",
                "华山派掌门岳不群的夫人。 \n"
               "她今年将近四十, 人称紫衫女侠.\n");
        set("gender", "女性");
        set("age", 36);
        set("attitude", "peaceful");
        set("shen_type", 1);
         set("marks/ningsword",3);
        set("str", 50);
        set("int", 50);
        set("con", 50);
 	set("per", 50);
        set("max_kee", 2000);
        set("max_gin", 1000);
	set("max_sen", 1000);
	set("atman", 1000);
	set("max_atman", 1000);
	set("mana", 1000);
	set("max_mana", 1000);
        set("force", 3000);
        set("max_force", 3000);
        set("force_factor", 150);
        set("combat_exp", 3000000);
        set("score", 40000);
        set_skill("force", 200);
        set_skill("zixia-shengong", 200);
        set_skill("dodge", 200);
        set_skill("huashan-shenfa", 200);
        set_skill("parry", 200);
        set_skill("sword", 180);
        set_skill("yunv-sword", 180);
        set_skill("purple", 180);
        set_skill("literate", 200);
        set_skill("strike", 200);
        set_skill("hunyuan-zhang", 200);
	set_skill("cuff", 200);
        set_skill("poyu-quan", 200);
        
        map_skill("strike", "hunyuan-zhang");
	map_skill("cuff", "poyu-quan");
        map_skill("force", "huashan-neigong");
	map_skill("dodge", "huashan-shenfa");
        map_skill("parry", "huashan-jianfa");
        map_skill("sword", "huashan-jianfa");

        prepare_skill("strike", "hunyuan-zhang");
	prepare_skill("cuff", "poyu-quan");

        create_family("华山派",18,"弟子");
        set("inquiry", ([
                "无双无对，宁氏一剑" : (: ask_xueyi :),
        ]) );
        setup();
        carry_object("/obj/weapon/changjian")->wield();
        carry_object("/d/huashan/obj/zishan")->wear();
}

void attempt_apprentice(object ob)
{
        if (ob->query("mark/剑宗"))
        {
        	command("sigh");
        	command("say "+RANK_D->query_respect(ob)+"乃是华山叛徒，我岂能收你？");
        	return;
        }
        if((int)ob->query("betrayer")>=10)
        {
                command("say "+RANK_D->query_respect(ob)+"多次背信弃义，我怎可收你。");
                return;
        }
        else if ((string)ob->query("gender")=="无性" && ob->query_skill("pixie-jian")>=50)
        {
                command("say 我看你向东厂派来的奸细。");
                return;
        }
        if((string)ob->query("gender")=="女性")
          {
               if ((int)ob->query("max_force") <200) {
                       command("say 我华山派原有剑宗、气宗之争。最终气宗为首。");
                       command("say " + RANK_D->query_respect(ob) +"是否还应该多练练内力？");
                       return;
               }
               if ((int)ob->query("shen") < 1000) {
                       command("say 学武之人，德义为先，功夫的高低倒还在其次，未练武，要先学做人。");
                       command("say 在德行方面，" + RANK_D->query_respect(ob) +"是否还做得不够？");
                       return;
               }
          command("say 好吧，" + RANK_D->query_respect(ob) +"，我就收下你了！");
          command("recruit "+ob->query("id"));
          ob->set("mark/气宗",1);

           }
        else {
          command("say 我不收男弟子，" + RANK_D->query_respect(ob) +"怎么能拿我开玩笑呢？你还是去拜我师兄吧！\n");
            };
}

void init()
{

        object me, ob;
        mapping fam;

        ::init();

        ob = this_player();
        me = this_object();
        if (((int)ob->query("shen")<500 || (int)ob->query("bad") >=3) && ((fam = ob->query("family")) && fam["master_id"] == "ning zhongze"))
        {
                command("say 你多次杀害好人，还屡教不改，我岂能仍是你的师傅。\n");
		ob->set("bad", 0);
                command("expell "+ ob->query("id"));
        }
}

void recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                if (this_player()->query("shen")<10000)
                {
                        ob->set("title",GRN "华山派" NOR + YEL +"女剑客" NOR);
                        return;
                }
                else
                {
                        ob->set("title",GRN "华山派" NOR + YEL +"女剑侠" NOR);
                        return;
                }

}

void re_rank(object student)
{
                if (this_player()->query("shen")<10000)
                {
                        student->set("title",GRN "华山派" NOR + YEL +"女剑客" NOR);
                        return;
                }
                else
                {
                        student->set("title",GRN "华山派" NOR + YEL +"女剑侠" NOR);
                        return;
                }
}

int ask_xueyi()
{ 
	object me;
		
	me = this_player();

	if( !me->is_apprentice_of(this_object()) )
	{
   		command("say 你不是我的弟子，这话又从何说起呢？\n");
		return 1;
	}
	if( me->query("max_force") < 800 )
	{
		command("say 你内力不足，使不出这一招来，还是好好练功吧。\n");
		return 1;
	}
	if( me->query_skill("sword") < 150 )
	{
		command("say 你剑术修为不够，使不出这一招来，还是好好练功吧。\n");
		return 1;
	}

	if( me->query("marks/ningsword") )
	{
		if( random(2) )
			command("kick "+me->query("id"));
		else
			command("kok "+me->query("id"));		
		command("say 又来和师傅我开玩笑了。\n");		
		return 1;
	}	

	command( "pat " + me->query("id") );
	command( "say 看来这位"+RANK_D->query_respect(me)+"是有缘之人，我就传你这一招了。\n" );
	tell_object(me,"你听了宁中则的讲解，明白了用剑当攻敌一点，不及其余的道理。\n你明白了「无双无对，宁氏一剑」的真谛！\n");
	me->set("marks/ningsword",1);
	return 1;
}
