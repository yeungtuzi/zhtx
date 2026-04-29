// 正邪宗师继承文件
// by Dongsw 2003

#include <ansi.h>

inherit NPC;

mapping basic_types = ([
        "axe"   :       "基本斧法",
        "dugong":      "基本毒功",
        "unarmed":      "基本拳脚",
        "sword":        "基本剑法",
        "blade":        "基本刀法",
        "hook":         "基本钩法",
        "hammer":       "基本锤法",
        "spear":        "基本枪法",
        "halberd":      "基本戟法",
        "fork":         "基本叉法",
//        "stick":        "基本棍法",
        "club":         "基本棍法",
        "staff":        "基本杖法",
        "throwing":     "基本暗器",
        "force":        "基本内功",
        "parry":        "基本招架",
        "dodge":        "基本轻功",
        "magic":        "基本法术",
        "spells":       "基本咒文",
        "move":         "基本行动",
        "array":        "基本阵法",
        "whip":         "基本鞭法",
        "finger":       "基本指法",
        "hand":         "基本手法",
        "cuff":         "基本拳法",
        "claw":         "基本爪法",
        "strike":       "基本掌法",
        "iron-cloth":   "铁布衫功",
        "h-force":      "高级内功",
]);

string *base_skill = keys(basic_types);

void set_basic_skill(object ob);
void view_skills();

void init()
{
        add_action("do_xuexi","xuexi");
}

void view_skills()
{
        int i, k, l;
        object ob = this_object(), me = this_player();
        write("以下这" + chinese_number(sizeof(base_skill)) + "种基本武功你想学哪个？\n\n");
        write(" ┏━━┳━━━━━━━━━━━┳━━┳━━━━━━━━━━━┳━━┳━━━━━━━━━━━┓\n");
        write(" ┃  n ┃ "HIW"武功名称    "HIG"武功代号"NOR
              " ┃  n ┃ "HIW"武功名称    "HIG"武功代号"NOR
              " ┃  n ┃ "HIW"武功名称    "HIG"武功代号 "NOR"┃\n"NOR);
        write(" ┠━━╋━━━━━━━━━━━╋━━╋━━━━━━━━━━━╋━━╋━━━━━━━━━━━┫\n");
        for(i=0;i<sizeof(base_skill);i++)
        {
                write(sprintf(" ┃ %2d ┃ %8s  %10s", i + 1, basic_types[base_skill[i]], base_skill[i]));
                if (i%3 == 2)
                write(" ┃\n");
        }
        l = 3-(sizeof(base_skill)%3);
        for(k=0;k<l;k++)
        {
                if( l == 3) break;
                if(k == l - 1)
                 write(sprintf(" ┃ -- ┃ %8s  %10s ┃\n", "--------", "----------"));
                else write(sprintf(" ┃ -- ┃ %8s  %10s", "--------", "----------"));
        }
        
        write(" ┗━━┻━━━━━━━━━━━┻━━┻━━━━━━━━━━━┻━━┻━━━━━━━━━━━┛\n\n");
}

        
void set_basic_skill(object ob)
{
        int i;
        
        for(i=0;i<sizeof(base_skill);i++)
        {
                if(base_skill[i] == "h-force")
                continue;
                ob->set_skill(base_skill[i],300);
        }
}

int do_xuexi(string arg)
{
        mapping map;
        string skill;
        object ob = this_object(), me = this_player();
        int master_skill, my_skill, gin_cost, point;

        if(!arg) return notify_fail("你要学习什么？\n");

        if(sscanf(arg, "%s with %d", skill, point) == 2 )
        {
                if(point <= 0 ) return notify_fail("你不是开玩笑吧.\n");
                if( point > ((int)me->query("potential")-(int)me->query("learned_points")) )
                        return notify_fail("你没有这么多的潜能。\n");
        }
        else if(sscanf(arg, "%s", skill) == 1 )
        {
                if( (int)me->query("learned_points") >= (int)me->query("potential") )
                        return notify_fail("你的潜能已经发挥到极限了，没有办法再成长了。\n");
                 point=1;
        }
        else  return notify_fail("请用 help experience 查看其用法。\n");

        if( me->is_busy() ) return notify_fail("你现在没有空！\n");
 
        if( me->is_fighting() )
                return notify_fail("临阵磨枪？来不及啦。\n");

        if( !living(ob) )
                return notify_fail("嗯....你得先把" + ob->name() + "弄醒再说。\n");
        
        if( me->query("宗师") != ob->name() )
                return notify_fail("你尚未取得向此武学宗师学习的资格。\n");

        if( me->query("combat_exp") < 8000000 )
//        if( me->query("combat_exp") < 12800000 )降低点要求，呵呵
                return notify_fail("你的武学经验太少了，宗师无法传授你更高级别的武功。\n");

        if( me->query("shen") >= 0 && ob->query("shen") < 0)
                return notify_fail("你浑身正气，欧阳峰不太想教你。\n");

        if( ob->query("shen") >= 0 && me->query("shen") < 0)
                return notify_fail("你浑身邪气，乔峰不太想教你。\n");

        if( skill == "h-force")
        {
                map = me->query_skill_map();
                if( !undefinedp(map["force"]) )
                {
                        my_skill = me->query_skill(map["force"], 1);
                        skill = map["force"];
                        master_skill = ob->query_skill(skill, 1);
                }
                else return notify_fail("你的高级内功尚未激发，请用 enable 激发高级内功。\n");

        }
        else 
        {
                my_skill = me->query_skill(skill, 1);

                if( !master_skill = ob->query_skill(skill, 1))
                        return notify_fail("这项技能你恐怕必须找别人学了。\n");

        }

        if( my_skill >= master_skill )
                return notify_fail("这项技能你的程度已经不输你师父了。\n");

        if( my_skill < 250 )
                return notify_fail("你这项技能的熟练程度还不够高，看起来宗师不太想指点你。\n");

        if( !SKILL_D(skill)->valid_learn(me) ) return 0;
        if( !SKILL_D(skill)->check_base_skill(me,skill) ) return 0;

        gin_cost = 150 / (int)ob->query("int") + 150 / (int)me->query("int");

        if( !my_skill ) {
                gin_cost *= 2;
                me->set_skill(skill,0);
        }
        if(me->query("gin") < gin_cost*point )
                point = me->query("gin")/gin_cost;
        gin_cost *= point;

        if( (int)me->query("learned_points") >= (int)me->query("potential") )
                return notify_fail("你的潜能已经发挥到极限了，没有办法再成长了。\n");

        if(!(int)me->query("env/message_brief"))
                printf("你向%s请教有关「%s」的疑问。\n", ob->name(),
                        to_chinese(skill));

        tell_object(ob, sprintf("%s向你请教有关「%s」的问题。\n", me->name(), to_chinese(skill)));

        if( (int)ob->query("sen") > gin_cost/5 + 1 ) 
        {
                if( userp(ob) ) ob->receive_damage("sen", gin_cost/5 + 1);
        }
        else
        {
                write("但是" + ob->name() + "显然太累了，没有办法教你什麽。\n");
                tell_object(ob, "但是你太累了，没有办法教" + me->name() + "。\n");
                return 1;
        }
                

        if( point>0 ) 
        {
                if( (string)SKILL_D(skill)->type()=="martial"
                && my_skill * my_skill * my_skill / 10 > (int)me->query("combat_exp") ) 
                printf("也许是缺乏实战经验，你对%s的回答总是无法领会。\n", ob->name() );
                else
                {
                        if(!(int)me->query("env/message_brief"))
                                printf("你听了%s的指导，似乎有些心得。\n", ob->name());
                        me->add("learned_points", point);
                        me->improve_skill(skill, point*random(me->query("int")+me->query_skill("literate")/5)*2/3);
                        me->receive_damage("gin", gin_cost );
                }
        }
        else write("你今天太累了，结果什麽也没有学到。\n");

        return 1;
}
