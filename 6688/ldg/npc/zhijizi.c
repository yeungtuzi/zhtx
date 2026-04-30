#include <ansi.h>

inherit NPC;
inherit "/ldg/std/adv_quest.c";
inherit "/ldg/std/rnd_equipd.c";

mapping c_prop=([
        "armor":"防御(armor)",
        "armor_vs_force":"防御(armor_vs_force)",
        "armor_vs_spells":"防魔法(armor_vs_spells)",
        "damage":"伤害力(damage)",
        "attack":"攻击力(attack)",
        "defense":"防御(defense)",
        "dodge":"轻功(dodge)",
        "add_max_kee":"加气",
        "add_max_sen":"加神",
        "add_max_gin":"加精",
        ]);

string ask_money();
int ask_task();
int generate_event(string path);
int money_quest();
int consider();


void create()
{
        set_name(HIY"知机子"NOR, ({ "zhiji zi","zi"}) );
        set("title",GRN"武林万事通"NOR);
        set("long",@LONG
据说对天下事情了如指掌，知道武林中许多鲜为人知的秘辛！
LONG
         );

        set("max_gin", 2000);
        set("max_kee", 5000);
        set("max_sen", 2000);
        set("max_force",4000); 
        set("force",8000);
        set("force_factor",300);
        set("combat_exp",29999999);
        set("str",100);
        set("cor",100);
        set("int",55);
        set("spi",50);
        set("cps",100);
        set("per",70);
        set("con",100);
        set("kar",30);

        set("age",66);
        set("atman", 4000);
        set("max_atman", 2000);
        set("mana", 4000);
        set("max_mana", 2000);
        set_temp("apply/armor",200);
        set_temp("apply/armor_vs_force",200);
        set_temp("apply/damage",200);

        set_skill("dodge",200);
        set_skill("tiyunzong",210);
        set_skill("force",320);
        set_skill("taiji-shengong",220);      
        set_skill("literate",200); 
        set_skill("taiji-jian",211);
        set_skill("move",200);         
        set_skill("parry",200); 
        set_skill("perception",150);
        set_skill("taoism",200);
        set_skill("sword",200);
        set_skill("music",50);
        set_skill("taiji-quan",200);
        set_skill("cuff",200);


        
        map_skill("force","taiji-shengong");
        map_skill("sword","taiji-jian");
        map_skill("parry","taiji-jian");
        map_skill("cuff","taiji-quan");
        map_skill("dodge","tiyunzong");
        map_skill("move","tiyunzong");
        prepare_skill("cuff","taiji-quan");
        
        
        set("inquiry",([
                  "money" : (: ask_money :),
                  "钱"    : (: ask_money :),
                  "task"  : (: ask_task  :),
                  "任务"  : (: ask_task  :),
        ]));
        
        set("chat_chance_combat", 80);  
        set("chat_msg_combat", ({
             (: consider :),
        }) );
        
        carry_object(__DIR__"obj/zjzsword")->wield();
        
        if(random(10)>8) carry_object(rnd_equip());

        setup();
        set("chat_chance", 3);
        set("chat_msg", ({
        }) );

        
}

void init()
{       
        object me=this_player();
        ::init();
        add_action("do_identify","identify");
        add_action("do_accept","accept");
        add_action("do_report","rept");
        add_action("do_report","report");
        add_action("do_sell","sell");
}

int do_report()
{
        int nowtime = time();
        int overtime,tasktime;
        mapping quest;
        object me;
 
        me=this_player();
        
        if(!(quest =  me->query("quest")))
                return notify_fail("你想报告什么！\n");
                
                if(quest["who"]!="zhiji zi") return notify_fail("我没有给过你任务！\n");

        tasktime = (int)  me->query("task_time");
        overtime = (int)  me->query("over_time");
        
        if(overtime && (overtime-tasktime) <= 0) 
        {
                tell_object(me,name()+"告诉你：恭喜你！你又完成了一项任务！\n" NOR);
                give_bonus(me,quest);    
        }    
        else if( (tasktime -  nowtime) < 0) {
                me->set("quest_ok",0);
                me->delete("quest");
                quest_punish(me);
        }
        else return notify_fail("你的任务还没完成！\n" NOR);
        return 1;
}

int generate_event(string path)
{
}


string ask_money()
{
        object me,ob;
        string gold_id;
        me = this_player();
        if(me->query("age")<15&&me->query("combat_exp")<1000)
        {
                gold_id=me->query("id");
                if(query(gold_id)) return "小小年纪切莫贪得无厌！\n";
                ob = new(GOLD_OB);
                ob->set_amount(1);
                ob->move(me);
                set(gold_id,1);
                return "这些钱你拿去用吧！\n";
        }
        else if(me->query("combat_exp")<100000)
        {
                message_vision("$N说道：钱不是问题，只要你替我办一些事，\n",this_object());
                message_vision("可惜你的能力不足以替我办好！\n",this_object());
                return "你再去闯荡几年江湖吧！\n";
        }
        else
        {
                return "天下没有白吃的午餐，你想要金子就先为我做一些任务把！\n";
        }
}

int ask_task()
{
        object me;
        me=this_player();
        if(me->query("combat_exp")<100000) 
        {
                tell_object(me,"知机子告诉你：你的能力不足以替我办事，你还是再去江湖上闯荡几年吧！！\n");
                return 0;
        }
        if(me->query("combat_exp")<1000000) give_quest("-h");
        else give_quest("");
        return 1;
}

int quest_punish(object who) {
    message_vision( (this_object())->query("name")+"拍拍$N的头，说道：你好好学学功夫再来吧！\n" ,who);
    return 0;
}

int accept_fight(object me)
{
        return notify_fail("知机子说道："+HIY"鄙人年事已高，岂能动则争气斗殴！\n"NOR);
}

int accept_object(object who, object ob)
{
        int t;
        if (t = ob->query("research"))
        {
                if(t == 250 && ob->query("owner") == who)
                {
                        message_vision("$n给了$N一枚" + ob->name() + NOR"。\n", this_object(),who);
                        command("nod");
                        message_vision(CYN"$N对$n说道：做得不错，希望你继续努力，为中原武林多做些贡献！\n"NOR, this_object(),who);
                        who->set("renkuang_winner",1);
                        destruct(present("moyu ling",who));
                        message("channel:chat", 
                        HIC + "【闲聊】" + name() + HIC"(" + capitalize(query("id")) +
                         ")：" + who->name() + "独闯魔域杀死了武林狐子任狂有功于武林，特允许" + 
                        who->name() + "研习更为高深的武学精要。\n"+NOR,users());
                        command("pat " + who->query("id"));
                        return 1;
                }
                else if(t == 400 && ob->query("owner") == who)
                {
                        message_vision("$n给了$N一颗" + ob->name() + NOR"。\n", this_object(),who);
                        command("nod");
                        message_vision(CYN"$N对$n说道：做得不错，希望你继续努力，为中原武林多做些贡献！\n"NOR, this_object(),who);
                        who->set("pangban_winner",1);
                        destruct(present("magic crystal",who));
                        message("channel:chat", 
                        HIC + "【闲聊】" + name() + HIC"(" + capitalize(query("id")) +
                         ")：" + who->name() + "勇闯幽明山庄、血洗接天楼并且杀死了魔师庞斑，特允许" + 
                        who->name() + "研习更为高深的武学精要。\n"+NOR,users());
                        command("pat " + who->query("id"));
                        return 1;
                }
        }
        return 0;
}

int  do_identify(string arg)
{
        object me, ob;
        object gold;
        int i,j,base,current;
        string id,name ;        
        string file,newfile,filestring,*props;
        mapping prop;
        me = this_player();
        id = me->query("id");
        if( !arg ) 
                return notify_fail("你要鉴别什麽东西？\n");
        gold = present("gold_money", this_player());
        if( !gold) 
                return notify_fail("你身上没有金子。\n");
        if((int) gold->query_amount() < 1 ) 
                return notify_fail("你身上没带够1两金子。\n");
        if( !objectp(ob = present(arg, me)) )
                return notify_fail("你身上没有这样东西。\n");
        if(me->is_busy())
                return notify_fail("你上一个动作还没有完成。\n");
        if(!ob->query("adv_props"))
                return notify_fail("知机子不鉴定这种东西。\n");
        gold->add_amount(-1);
        me->start_busy(1);
        name = ob->query("name");
        tell_object(me,"知机子告诉你：这是一件"+name+"。\n");
        if(ob->query("random")) tell_object(me,YEL"装备等级："+ob->query("level")+"。\n"NOR);
        prop=ob->query("adv_props");
        props=keys(prop);
        for(i=0;i<sizeof(props);i++)
                tell_object(me,YEL+c_prop[props[i]]+"："+sprintf("%d",prop[props[i]])+"。\n"NOR);
        return 1;
}


int consider()
{
        object me;
        // 2026-04-30: unused variable commented out
        // int fighting,hurt,force_fac;

        me = this_object();
        if( !environment(me) ) return 0;
        
        //消除自己的busy
        if( random(4) > 2 && is_busy() )
                interrupt_me(this_object(),"death");
        //自动疗伤
        if(query("eff_kee")<query("max_kee")*50/100&&query("guo")<3)
        {
                add("guo",1);
                set("eff_gin", (int)query("max_gin"));
                set("gin", (int)query("max_gin"));
                set("eff_kee", (int)query("max_kee"));
                set("kee", (int)query("max_kee"));
                set("eff_sen", (int)query("max_sen"));
                set("sen", (int)query("max_sen"));       
                set("max_force", (int)query("max_force"));
                set("max_mana", (int)query("max_mana"));
                set("max_atman", (int)query("max_atman"));
                message_vision(HIG"$N吃下一枚人参果，只觉得精神健旺，气血充盈，体内真力源源滋生，甚至不再感到饥饿干渴! \n"NOR,me);
        }
        
        //自动解毒
        if( query("auto_unpoison") && (query_condition("tm_poison") || query_condition("rose_poison") || query_condition("snake_poison")) )
        {
                command("halt");
                command("exert unpoison");
        }                            
        if(query("sen")<(query("eff_sen")*70/100))
                command("exert refresh");
        if(query("kee")<(query("eff_kee")*70/100))
                command("exert recover");
        if(query("gin")<(query("eff_gin")*70/100))
                command("exert regenerate");
}

int do_sell(string arg)
{
        string *name;
        object ob;
        int value;
        object owner;
        mapping armor_prop, applied_prop,adv_armor_prop,equips;
        // 2026-04-30: unused variable commented out
        // string *apply,*adv_apply,type;
        string file;

        
        if (!arg || !(ob = present(arg, this_player())))
                return notify_fail("你要卖什么？\n");

        if (ob->query("money_id"))
                return notify_fail("你想卖「钱」？？\n");

        if (ob->query("no_drop")&&!ob->query("adv_props"))
                return notify_fail("这样东西不能卖。\n");

        if (ob->query("no_sell")&&!ob->query("adv_props"))
                return notify_fail("这样东西不能卖。\n");

        if (ob->query("food_supply"))
                return notify_fail("剩菜剩饭留给您自己用吧。\n");

        if( ob->query("shaolin") )
           return notify_fail("这是佛门的东西，小店可不敢收，真是罪过！\n");

 
        file=base_name(ob);
        file=file+"#"+sprintf("%d",ob->query("unique_id"));
        owner = this_player();

        if( (!mapp(equips=owner->query("adv_equips")) || !arrayp(equips[file])) )
        {
                return notify_fail("这不是你的东西。\n");
        }


        value = ob->query("value");
        if (value < 10)
                return notify_fail(ob->name() + "一文不值！\n");
        {
                message_vision("$N卖掉了一" + ob->query("unit") + 
                ob->name() + "给$n。\n", this_player(), this_object());

                MONEY_D->pay_player(this_player(), value*4/5);
                if(ob->query("adv_props")) ob->detach();
                else destruct(ob);
              }
        return 1;
}

