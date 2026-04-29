#include <ansi.h>
// yang.c 扬过

inherit NPC;
inherit F_MASTER;
string ask_me();

string ask2();
void heal();

void create()
{
        set_name("杨过", ({ "yang guo", "yang","guo" }));
       set("nickname", HIR "西狂" NOR);
        set("long",
                "他就是古幕派的扬过、人们都叫他神雕大侠。\n"
                "身穿一件灰衣。\n"
                "身材高大，三十多岁的样子，据说蒙古皇帝蒙哥就是他杀的。\n");
        set("title",HIC "终南山" NOR + HIG "隐士" NOR);
        set("gender", "男性");
        set("age", 32);
        set("attitude", "friendly");
        set("shen_type", 1);
        set("str", 25);
        set("int", 30);
        set("con", 30);
        set("dex", 20);

        set("max_kee", 8000);
        set("max_gin", 4000);
        set("max_sen", 4000);
        set("force", 10000);
        set("max_force", 5000);
        set("force_factor", 350);
        set("combat_exp", 20000000);
        set("score", 300000);

        set("chat_chance", 100);
        set("chat_msg", ({
	        (: heal :),
        }));


        set_skill("force", 220);
        set_skill("jiuyin-shengong", 220);
        set_skill("dodge", 200);
        set_skill("xianyun", 200);
           set_skill("strike", 200);
        set_skill("anran-zhang", 200);
        set_skill("parry", 200);
        set_skill("xuantie-sword", 220);
        set_skill("sword", 220);
        set_skill("iron-cloth", 220);
        set_skill("quanzhen-jian", 180);
        set_skill("cuff",180);
	set_skill("meinu-quan",180);
        set_skill("literate", 100);
	set("book_count",1);

        map_skill("force", "jiuyin-shengong");
        map_skill("dodge", "xianyun");
           map_skill("cuff", "meinu-quan");
//        map_skill("strike","xiaohun-zhang");
        map_skill("parry", "xuantie-sword");
        map_skill("iron-cloth", "jiuyin-shengong");
        map_skill("sword", "xuantie-sword");
//        prepare_skill("strike", "xiaohun-zhang");

        create_family("古墓派", 4, "弟子");
	 set("chat_chance", 100);
        set_temp("apply/attack", 100);
         set_temp("apply/armor_vs_force",200);
         set_temp("apply/armor",200);
        set_temp("apply/defense", 100);
        set_temp("apply/damage", 200);
         set("inquiry", ([
   "君子剑" : (: ask_me :),
                
                "黯然销魂": (: ask2 :),
        ]) );
       

        setup();
         carry_object("/d/quanzhou/obj/xtsword")->wield();
        
}


void heal()
{
	object ob=this_object();
	
	if (ob->query("eff_kee") < ob->query("max_kee"))
	{
		command("exert heal");
		command("enforce 100");
		return;
	}

	if (ob->query("kee") < ob->query("eff_kee"))
	{
		command("exert recover");
		return;
	}

	if (ob->query("gin") < ob->query("eff_gin"))
		command("exert regenerate");

	return;
}
void attempt_apprentice(object ob)
{
        if((string)ob->query("family/family_name")!="古墓派")
                {
                 command("say " + RANK_D->query_respect(ob) + "若想拜我派可先拜小虹小玲.");
                return;
                }
        if((int)ob->query_skill("yunu-xinfa",1)<201)
		{
                command("say " + RANK_D->query_respect(ob) + "玉女心经火候不够，不适合学我的功夫。");
                return;
                }
        if((int)ob->query("max_force")<500)
		{
                 command("say " + RANK_D->query_respect(ob) + "内力太低，不适合练我的功夫。"); 
                return;
                }
        if (((int)ob->query("dex")+(int)ob->query_skill("dodge",1)/10)<20)
      {
                command("say" + "我古墓派的功夫以轻灵为主，" + RANK_D->query_respect(ob) + "似乎对轻功不太重视吧。");
  return;
                }
        else
          {
        command("say 好吧，"+RANK_D->query_respect(ob)+"，我就收下你了！");
        command("recruit "+ob->query("id"));
           }
       
}
void recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                {	
			if(ob->query("gender")=="女性")
                        ob->set("title",GRN "古墓派" NOR + MAG +"圣女" NOR);
                        
			else
			ob->set("title",GRN "古墓派"NOR + MAG + "圣使" NOR);
			return;
               
		}
}
void re_rank(object student)
{	if(student->query("gender")=="女性")
        student->set("title",GRN "古墓派" NOR + MAG +"圣女" NOR);
	else student->set("title",GRN "古墓派"NOR + MAG + "圣使" NOR);  
      return;
             
}
string ask_me()
{	 mapping fam;
        object ob;
         object me=this_player();
            if (!(fam = this_player()->query("family"))
            || fam["family_name"] != "古墓派")
             return RANK_D->query_respect(this_player()) +
                "与本派素无来往，不知此话从何谈起？";
        if((int)me->query_skill("quanzhen-jianfa",1)<80)
        return "你的全真剑法太低，要了君子剑也发挥不出它的威力。";
        if (query("book_count") < 1)
                return "你来晚了，本派的君子剑不在此处。";
        add("book_count", -1);
        ob = new("/d/gumu/obj/sword2");
        ob->move(this_player());
        return "好吧，这把君子剑你拿回去好好保管。";
}
string ask2()
{mapping fam;
        object me=this_player();
        if (!(fam = this_player()->query("family")) || fam["family_name"] != "古墓派" )
                return RANK_D->query_respect(this_player()) +
                "与本派素无来往，不知此话从何谈起？";
        else
        {
        message_vision("杨过说道：“好吧，我就教你黯然销魂一式吧。”\n",me);
       
        me->set("anran",1);
 return "记住，不要用我教你的来作恶，不然我决不轻饶。\n";
        }
}        
