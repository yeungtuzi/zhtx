//daoshi2.c 扫地道士
//by emote
inherit __DIR__"jian_npc.c";

#include <ansi.h>
void create()
{
        set_name("扫地道士", ({ "saodi daoshi", "daoshi", "taoist" }) );

        set("gender", "男性");
        set("age", 25+random(15));
        set("attitude", "peaceful");
        
        set("str", 42);
        set("cor", 50);
        set("int", 24);
        set("cps", 50);


        set("force", 1000);
        set("max_force", 1000);
        set("force_factor", 100);

        set("combat_exp", 500000);
        set("inquiry", ([
                "长老": "我记得打小我在这里的时候，长老就在这里了。\n",
                "秘密": "咱们这西岳庙哪有什么秘密？\n",
                "宝贝": "西侧殿那块《西岳华山庙碑》就是咱这西岳庙的镇山之宝，可宝贵着呢。"
         ]) );
/*        set("chat_chance", 1);
        set("chat_msg", ({
		"香火道人故作神秘地说：前段时间半夜我值更的时候，经常看见有个人影从长老的屋子里出来。\n",
}));
*/
       
        set_skill("strike", 100);
        set_skill("sword", 100);
        set_skill("force", 100);
        set_skill("parry", 100);
        set_skill("dodge", 100);
        set_skill("literate", 100);
        
        set_skill("huashan-jianfa", 100);
        set_skill("hunyuan-zhang", 100);
        set_skill("huashan-neigong", 100);
        set_skill("huashan-shenfa", 100);

        map_skill("sword", "huashan-jianfa");
        map_skill("parry", "huashan-jianfa");
        map_skill("force", "celestial");
        map_skill("strike", "hunyuan-zhang");
        map_skill("dodge", "huashan-shenfa");
        map_skill("move", "huashan-shenfa");
	
	prepare_skill("strike", "hunyuan-zhang");
        
        set("shen_type",-1);
        setup();

        carry_object(OBJ_DIR"weapon/sword.c")->wield();
        carry_object(__DIR__"obj/greyrobe")->wear();
}
