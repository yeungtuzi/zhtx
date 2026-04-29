// xiaohong.c 小虹
#include <ansi.h>
inherit NPC;
inherit F_MASTER;
/*string ask_me();
void consider();*/
void create()
{
        set_name("小虹", ({ "xiao hong","hong" }));
        
         set("title",GRN "古墓派" NOR + YEL +"女使" NOR);
        set("long",
                "她是古墓派的使女\n"
                "她看起来十多岁，容貌秀丽，别有一番可人之处。\n");
        set("gender", "女性");
        set("age", 16);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 18);
        set("int", 28);
        set("con", 20);
        set("dex", 24);
        set("per", 25);
        set("max_kee", 600);
        set("max_gin", 300);
        set("force", 600);
        set("max_force", 600);
        set("enforce", 50);
        set("combat_exp", 50000);
        set("score", 5000);

	 set_skill("force", 60);
        set_skill("yunu-xinfa", 60);
	set_skill("cuff", 70);
	set_skill("meinu-quan", 70);
        set_skill("dodge", 80);
        set_skill("xianyun", 80);
        set_skill("parry", 70);
        set_skill("whip", 70);
        set_skill("xiangmei-bian", 70);
	set_skill("throwing",70);
	set_skill("zhinv-zhen",70);
        set_skill("literate", 50);

       

        map_skill("force", "yunu-xinfa");
	map_skill("cuff", "meinu-quan");
        map_skill("dodge", "xianyun");
//      map_skill("unarmed", "taiji-quan");
        map_skill("parry", "xiangmei-bian");
        map_skill("whip", "xiangmei-bian");

	prepare_skill("cuff", "meinu-quan");

       

        create_family("古墓派" , 5, "弟子");
        setup();
        carry_object("/d/shaolin/obj/changbian")->wield();
        carry_object("/d/gumu/obj/black")->wear();
}
void attempt_apprentice(object ob)
{
        
	if( ob->query("gender")!="女性" || ob->query("husband") || ob->query("marry_betrayer") )
	{
		command("say 我派只收冰清玉洁的女儿家。");
		return;
	}	
        command("say 好吧，"+RANK_D->query_respect(ob)+"，我就收下你了！");
        command("recruit "+ob->query("id"));
 if (this_player()->query("age")<16)
        {
        if((string)this_player()->query("gender")!="女性")
                this_player()->set("title",RED "古墓派" NOR + GRN +"男童" NOR);
        else

                this_player()->set("title",RED "古墓派" NOR + GRN +"女童" NOR);
        }
        else {
        if((string)this_player()->query("gender")!="女性")
                this_player()->set("title",RED "古墓派" NOR + GRN +"使者" NOR);
        else
                this_player()->set("title",RED "古墓派" NOR + GRN +"使女" NOR);
        }
        
}

