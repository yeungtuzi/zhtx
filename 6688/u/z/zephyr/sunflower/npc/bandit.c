//by zephyr

#include <ansi.h>
inherit "/u/z/zephyr/sunflower/npc/anpc";
void create()
{
        int lvl,t,i;
        lvl=random(3)+4;

        set("level",lvl);

        if (lvl==4) 
        set_name(YEL"蒙面大盗"NOR, ({ "bandit"}) );

        else if (lvl==5)
        set_name(GRN"蒙面大盗"NOR, ({ "bandit"}) );

        else if (lvl==6)
        set_name(RED"蒙面大盗"NOR, ({ "bandit"}) );

        set("long",BLK@LONG
他穿着紧身的夜行衣，用一块黑布蒙面，身法快如急风，
轻如飞絮，远远的就让人感到他身上的一股杀气。
LONG NOR
         );
        set("title",BLK"无恶不作"NOR);
        set("age",32);

        //set advanced skills
        t=230+(6-lvl)*25;


        set_skill("force", t+random(10));
        set_skill("taiji-shengong", t+random(10));
        set_skill("huntian-qigong", t+random(10));
        set_skill("zixia-shengong", t+random(10));

        set_skill("magic", t+random(10));
        set_skill("essencemagic", t+random(10));

        set_skill("dodge", t+random(10));
        set_skill("stormdance", t+random(10));
        set_skill("bat-steps", t+random(10));
        set_skill("baguabu", t+random(10));
        set_skill("tiyunzong", t+random(10));
        set_skill("xianyun", t+random(10));

        set_skill("cuff", t+random(10));
        set_skill("jingang-quan",t+random(10));
        set_skill("taiji-quan", t+random(10));
        set_skill("qishang-quan", t+random(10));
        
        set_skill("claw", t+random(10));
        set_skill("spicyclaw", t+random(10));
        set_skill("sougu", t+random(10));

        set_skill("blade", t+random(10));
        set_skill("shortsong-blade", t+random(10));

        set_skill("strike", t+random(10));
        set_skill("bloodystrike", t+random(10));
        set_skill("meihua-shou", t+random(10));
        set_skill("sanhua-zhang", t+random(10));
        
        set_skill("sword", t+random(10));
        set_skill("dugu-jiujian", t+random(10));
        set_skill("pixie-sword", t+random(10));
        set_skill("taiji-jian", t+random(10));
	    set_skill("six-chaos-sword", t+random(10));
        set_skill("divine-mystsword", t+random(10));
        set_skill("parry", t+random(10));
        set_skill("perception", t+random(10));
        setup();

//随机初始化功夫map
//首先选择一种内力
        i=random(3);
        if (i==2)       map_skill("force","taiji-shengong");
        if (i==1)       map_skill("force","huntian-qigong");
        if (i==0)       map_skill("force","zixia-shengong");
//魔法只有一种：（
        map_skill("magic", "essencemagic");
//选定一种轻功
        i=random(5);
        if (i==4)       {map_skill("dodge","xianyun"); map_skill("move","xianyun");}
        if (i==3)       {map_skill("dodge","stormdance");       map_skill("move","stormdance");}
        if (i==2)       {map_skill("dodge","bat-steps");    map_skill("move","bat-steps");}
        if (i==1)       {map_skill("dodge","tiyunzong");        map_skill("move","tiyunzong");}
        if (i==0)       {map_skill("dodge","baguabu");  map_skill("move","qimen-bagua");}
//选择一种空手功夫
        i=random(8);
//cuff
        if (i==7)       {map_skill("cuff","jingang-quan");prepare_skill("cuff","jingang-quan");}
        if (i==6)       {map_skill("cuff","taiji-quan");prepare_skill("cuff","taiji-quan");}
        if (i==5)       {map_skill("cuff","qishang-quan");prepare_skill("cuff","qishang-quan");}
//claw
        if (i==4)       {map_skill("claw","spicyclaw");prepare_skill("claw","spicyclaw");}
        if (i==3)       {map_skill("claw","sougu");prepare_skill("claw","sougu");}
//strike
        if (i==2)       {map_skill("strike","bloodystrike");prepare_skill("strike","bloodystrike");}
        if (i==1)       {map_skill("strike","meihua-shou");prepare_skill("strike","meihua-shou");}
        if (i==0)       {map_skill("strike","sanhua-zhang");prepare_skill("strike","sanhua-zhang");}
//选择一种兵器
        i=random(5);
        if (i==4)       map_skill("sword","divine-mystsword");
        if (i==3)       
        {
                set_skill("xuantie-sword",t+random(10));
                map_skill("sword","xuantie-sword");
        }
        if (i==2)       map_skill("sword","dugu-jiujian");
        if (i==1)       map_skill("sword","taiji-jian");
        if (i==0)       
        {
            set_skill("fonxansword",t+random(10));
                map_skill("sword","fonxansword");
				set("percmd","perform sword.counterattack");
        }
//选择一种招架
        i=random(4);
        if (i==3)       map_skill("parry","divine-mystsword");
        if (i==2)       map_skill("parry","meihua-shou");
        if (i==1)       map_skill("parry","taiji-quan");
        if (i==0)       map_skill("parry","taiji-jian");
//现在来决定用空手还是用一种兵器
        carry_object("/obj/weapon/sword")->wield();
        set("weapon_type","sword");
        carry_object("/obj/cloth/cloth")->wear();
        remove_call_out("dest_npc");
        call_out("dest_npc",600);
}

void dest_npc()
{
        tell_room(environment(this_object()),"\n"+query("name")+
                "拍拍身上的尘土，飘然远去了……\n\n");
        destruct(this_object());
}                          
