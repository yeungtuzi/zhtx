// fumo.c 金刚伏魔
//by masterall

inherit F_DBASE
inherit F_SSERVER

void remove_effect(object me, int amount)
varargs show_combat_msg(int level,object me,object victim,object weapon,mapping action,string attack_skill)
{
        string limb, *limbs, result
        
        
        if( limb )

        if( victim->query_skill_mapped(iron-cloth))

        if( victim->query_temp(weapon))

        if( objectp(weapon) )
        else if( action && stringp(actionweapon) )
        else if( attack_skill == finger )
        else if( attack_skill == strike )
        else result = replace_string( result, $w, 拳头 )
        
        result += ！\n

        message_combat(level,result, me, victim )
}

void post_action1(object me, object victim, int damage_bonus)
{}

void post_action2(object me, object victim, int damage_bonus)
{}

void post_action3(object me, object victim, int damage_bonus)
{}

void post_action4(object me, object victim, int damage_bonus)
{}

void post_action5(object me, object victim, int damage_bonus)
{}

void post_action6(object me, object victim, int damage_bonus)
{}

void post_action7(object me, object victim, int damage_bonus)
{}

void post_action8(object me, object victim, int damage_bonus)
{}

void post_action9(object me, object victim, int damage_bonus)
{}

mapping *actions = ({
([      action:               $N端坐不动，一招「裂石式」，手中$w抖得笔直，对准$n的胸腹要害连刺数鞭,
        "force":                100,
        "dodge":                20,
        "parry":                20, 
        "attack":               20,
        "damage":               100,
        "post_action":  (: call_other, __FILE__, "post_action1" :),
        "skill_name" : "裂石式",
        "damage_type":  "刺伤"
]),
 ([     action : $N使一式「摘星换斗」，劲气弥漫，双掌如轮，一环环向$n的$l斫去,
         "force" : 450,
         "attack": 30,
         "parry" : 30,
         "dodge" : 20,
         "post_action":  (: call_other, __FILE__, "post_action2" :),
         "undodgeable":10,
         "damage_type" : "劈伤",
        "skill_name" : "摘星换斗"
 ]),
 ([     action : $N一式「观音渡」，两手十指虚点$n的全身三十六道要穴,
        "force" : 380,
         "dodge" : 25,
        "attack": 35,
         "unparryable" : 10,
         "post_action":  (: call_other, __FILE__, "post_action3" :),
        "skill_name" : "观音渡",
         "damage_type" : "瘀伤"
 ]),
([      action:               $N身形一转，一招「断川式」，手中$w如矫龙般腾空一卷，猛地向$n劈头打下,
        "force":                125,
        "attack":               30,
        "dodge":                30,
        "parry":                30,
        "damage":               125,
         "post_action":  (: call_other, __FILE__, "post_action4" :),
        "skill_name" : "断川式",
        "damage_type":  "刺伤"
]),
 ([     action : $N两掌上下护胸，一式「翻江搅海」，骤然化为满天掌雨，攻向$n,
         "force" : 500,
         "attack": 40,
         "parry" : 30,
         "dodge" : 30,
         "post_action":  (: call_other, __FILE__, "post_action5" :),
         "undodgeable":20,
         "damage_type" : "瘀伤",
        "skill_name" : "翻江搅海" 
 ]),
 ([     action : $N两目内视，双手内笼，一式「天龙唱」，四面八方响起震人心魄的龙吟,
        "force" : 680,
         "dodge" : 15,
        "attack": 40,
         "unparryable" : 20,
         "post_action":  (: call_other, __FILE__, "post_action6" :),
        "skill_name" : "天龙唱",
         "damage_type" : "瘀伤"
 ]),
([      action:               $N力贯鞭梢，一招「破云式」，手中$w舞出满天鞭影，排山倒海般扫向$n全身,
        "force":                150,
        "attack":               40,
        "dodge":                40,
        "parry":                40,
        "damage":               150,
        "unparryable":          20,
         "post_action":  (: call_other, __FILE__, "post_action7" :),
        "skill_name" : "破云式",
        "damage_type":  "刺伤"
]),
 ([     action : $N一式「金刚伏魔」，双手合十，对着$n微微一揖，全身内劲如巨浪般汹涌而出,
         "force" : 600,
         "attack": 40,
         "parry" : 35,
         "dodge" : 35,
         "post_action":  (: call_other, __FILE__, "post_action8" :),
         "undodgeable":30,
         "damage_type" : "瘀伤",
        "skill_name" : "金刚伏魔"
 ]),
 ([     action : $N似笑非笑，双拳无形无定，一式「如来笑」，骤然击向$n的前胸,
        "force" : 880,
         "dodge" : 20,
        "attack": 40,
        "unparryable": 30, 
         "post_action":  (: call_other, __FILE__, "post_action9" :),
        "skill_name" : "如来笑",
         "damage_type" : "瘀伤",
 ]),
})

int perform(object me, object target)
{
        int skill
        string weapon
        int damage
        string *limb, type, result, str
        object ob

        if( !target ) target = offensive_target(me)
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail(金刚伏魔只能在战斗中使用。\n)

        if( me->query(betrayer)>0 )
                return notify_fail(背叛师门的人怎么能使用少林绝技?\n)

        if( me->query_skill_mapped(force) != hunyuan-yiqi )
                return notify_fail(你所用的并非混元一气功，无法施展金刚伏魔！\n)

        if( me->query_skill(hunyuan-yiqi, 1) < 250)
                return notify_fail(你的混元一气功火候未到，无法施展金刚伏魔！\n)

        if( me->query_skill(riyue-bian, 1) < 250 )
                return notify_fail(你的日月神鞭火候未到，无法施展金刚伏魔！\n)

        if( me->query_skill(buddhism, 1) < 200 )
                return notify_fail(你的佛法修为太低，无法施展金刚伏魔！\n)

        if( me->query(faith, 1) < 20000 )
                return notify_fail(你的门忠不够，还没学会金刚伏魔！\n)

        if (!objectp(ob = present(hei suo,me) ) )
                return notify_fail(你还没有得到黑索，如何使用金刚伏魔？\n)

        if( (int)me->query_temp(skill_mark/fumo))
                return notify_fail(金刚伏魔正在运行中！\n)

        if( me->query(max_force) <= 3090 )
                return notify_fail(你的内力修为不足，无法施展金刚伏魔！\n)

        if( (int)me->query(force) < 3000  )
                return notify_fail(你的内力不够。\n)
        {
        message_vision(HIC $N一宣佛号：“我佛慈悲，贫僧今天要大开杀戒了！”\n话音未落，+BLK黑  索+HIC倏地飞起，疾向$n身上卷来！\n NOR, me,target)
        }
        me->set_temp(skill_mark/fumo,1)

        message_vision( HIC$N将+BLK黑  索+HIC舞得如同一条张牙舞爪的墨龙相似，急升而上，分从前后夹击耳到！\nNOR,me,target)
        if( target->query_skill(dodge)+target->query_skill(parry)* 2/3  random((me-query_skill(whip) + me->query_skill(force))*4/3))
        {
                if(damage < 200) damage = 200
                me->add(force, -me->query(enforce)/2)

                target->receive_damage(kee, damage,  me)
                target->receive_wound(kee, (int)me->query_skill(whip), me)

                message_vision(HIR$N突觉身周气流略有异状，这一下袭击事先竟无半点朕兆，一惊之下，\n+BLK黑  索+HIR已然击中了$P+limbrandom+，$P登时肋骨断折，“啊”得一声惨叫！\nNOR,target)

                message_vision(($N+str+)\n, target)
                if(me->query_skill(buddhism, 1)>=220 )
                {
                remove_call_out(pfm2)
                call_out(pfm2, 2, me, target)
                }
                else
                {
                me->delete_temp(skill_mark/fumo)
                }
                me->start_busy(1+random(2))
                target->start_busy(1+random(4))
        }
        else if( ( random( target->query_skill(parry) ) >  me->query_skill(whip)*2/3) && random(3) == 1 )
        {
                message_vision(HIR$N左手一翻，抓住当胸点来的那条+BLK黑  索+HIR，正想从旁甩去，\n突觉那条长索一抖，一股排山倒海的内劲向胸口撞到，\n$n只觉得喉头发甜，“哇”的一声吐出一口鲜血！\nNOR, target,me )
                target->receive_damage(kee, 250+random(50),  me)
                target->receive_wound(kee, 250+random(50),  me)
                target->add(force,-500)
                target->start_busy(1+random(1))
                message_vision(($N+str+)\n, target)
                me->delete_temp(skill_mark/fumo)
        }
        else
        {
                message_vision( HIG$N这电光石火般的一刹那间，右手后挥，拨开了从身后袭至的+BLK黑  索+HIG，\n一提一送，身随劲起，嗖的一声，身子直冲上天。 \n\n NOR,  target,me)
                me->start_busy(1)
                me->delete_temp(skill_mark/fumo)
        }
        me->add(force, -200)
        me->start_busy( 1 )
        target->start_busy( 5 )

        return 1
}
int pfm2(object me, object target)
{
        int t,i

        if (!me)
        {
        me->delete_temp(skill_mark/fumo)
        return 1
        }
        if (!(objectp(present(target->query(id), environment(me)))))
        {
        me->delete_temp(skill_mark/fumo)
        return 1
        }
        if(!living(target))
        {
        me->delete_temp(skill_mark/fumo)
        return 1
        }
        me->add_temp(apply/damage, t/6)
        me->add_temp(apply/attack, t/4)
        message_vision(HIG\n$N突然停手不攻，不断的诵念“金刚经”：“尔时须菩提闻说是经，深解义趣，\n涕泪悲泣，而白佛言：‘希有世尊，佛说如是甚深经典。我从昔来所得慧眼，\n未曾得闻如是之经。世尊，若复有人得闻是经，信心清净，即生实相……’”\n\n$n听到此处，心中思潮起伏，自知自知孽重罪深，却忘了此时是生死相搏之间！\n\n$n眼前疾光一闪，+BLK黑  索+HIG向胸口点到，\n那+BLK黑  索+HIG化成一条笔直的兵刃，如长矛，如杆棒，疾刺而至！\n\n NOR, me,target)
                                for(i=0;i<6;i++)
                                {
                                 COMBAT_D->do_attack(me, target, me->query_temp(weapon))
/*                if(!objectp(target) 
                   || target->is_ghost() 
                   || target->query(eff_kee) < 1
                   || (environment(me)!=environment(target))
                   || me->is_ghost()) 
                                        {       
              message_vision(HIC $N轻颂佛号：“阿弥陀佛，造孽造孽！”，顿时满目凄凉之色。\n NOR, me)
              me->delete_temp(skill_mark/fumo)
              me->add_temp(apply/damage, -t/2)
              me->add_temp(apply/attack, -t/4)
                                                break
                                        }
*/                                                   
                                 }
        me->add_temp(apply/damage, -t/6)
        me->add_temp(apply/attack, -t/4)
        me->add(force, -50)
        if (me->query_skill(buddhism, 1)>=250 )
        {
        remove_call_out(pfm3)
        call_out(pfm3, 2, me, target)
        }
        else
        {
        me->delete_temp(skill_mark/fumo)
        }
        return 1

}

int pfm3(object me, object target)
{
        int t,i,per_power,per_lev,victim_exp,num
     //   object ob
     //   ob = me->query_temp(weapon)
        if (!me)
        {
        me->delete_temp(skill_mark/fumo)
        return 1
        }
        if (!(objectp(present(target->query(id), environment(me)))))
        {
        me->delete_temp(skill_mark/fumo)
        return 1
        }
        if(!living(target))
        {
        me->delete_temp(skill_mark/fumo)
        return 1
        }
        me->add_temp(apply/damage, t/5)
        me->add_temp(apply/attack, t/3)
        message_vision( HIY\n只听$N继续念诵：“‘世尊，我今得闻如是经典，信解受持，不足为难。\n若当来世，后五百岁，其有众生得闻是经，信解受持，是人即为第一希有。何以故？\n此人无我相、无人相、无众生相、无寿者相……’”\n\n$n心灵渐受感应，突然间哈哈哈仰天三笑，声音中竟充满了邪恶奸诈之意。\n\n$N眉头微躇，嗔道，“既然施主如此冥顽不化，那贫僧就送你归西吧！”\n\n$N右手的+BLK黑  索+HIY一抖，向$n扑击而至，但一动念间左手又将“须弥山掌”拍了出来！\n\n NOR, me,target)
        for(i=0;i<9;i++)
        {
                if(!objectp(target) 
                   || target->is_ghost() 
                   || target->query(eff_kee) < 1
                   || (environment(me)!=environment(target))
                   || me->is_ghost())             
                {
                         message_vision(HIC $N轻颂佛号：“阿弥陀佛，造孽造孽！”，顿时满目凄凉之色。\n NOR, me)
                        break
                } 
                
                if( !me->visible(target) )
                {
                        if(per_power<victim_exp/4)
                        {
                                if( per_power>victim_exp/8 )
                                message_vision(GRN\n$N身形凝立不动，侧耳倾听。\nNOR,me)
                                me->set_temp(guarding, 1)
                                continue
                        }                               
                        message_vision(YEL\n$N从$n衣袂带风声中感应出$n身形所在，趁势发动攻击！\nNOR,me,target)
                }  

                show_combat_msg(5,me,target,me->query_temp(weapon),actionsi,whip)
                COMBAT_D->do_attack(me,target,me->query_temp(weapon),TYPE_SELFATTACK,actionsi)
        }
        me->add_temp(apply/damage, -t/5)
        me->add_temp(apply/attack, -t/3)
        me->add(force, -50)
        if (me->query_skill(buddhism, 1) >=300 
         && me->query_cps()  random(target-query(cps)) )
        {
        remove_call_out(pfm4)
        call_out(pfm4, 2, me, target)
        }
        else if (me->query_skill(buddhism, 1) >=300 
         && me->query_cps() >= random(target->query(cps)) )
        {
        remove_call_out(pfm5)
        call_out(pfm5, 2, me, target)
        }
        else
        {
        me->delete_temp(skill_mark/fumo)
        }
        return 1

}
int pfm4(object me, object target)
{
        int t,i
        me->delete_temp(skill_mark/fumo)
        if (!me) return 1
        if(!living(target)) return 1
        if (!(objectp(present(target->query(id), environment(me)))))
        return 1
        me->add_temp(apply/damage, t/4)
        me->add_temp(apply/attack, t/2)
        message_vision( HIW\n$N又念经道：“佛告须菩提：‘如是，如是！若复有人得闻是经，不惊，不怖，不畏，\n当知是人甚为希有……如我昔为歌利王割截身体，\n我于尔时，无我相、无人相、无众生相、无寿者相。何以故？\n我于往昔节节支解时，若有我相、人相、众生相、寿者相，应生嗔狠……菩萨须离一切相。’”\n\n$n于经义终有所悟，想到了经文中的含义，心魔便即消退，武功立时不能连贯！！\n\n$N拈花一笑，赞许的点了点头，“善哉，善哉，既然如此，贫僧便为施主超度了吧！！\n\n” NOR, me,target)
                                for(i=0;i<4;i++)
                                {
                                 COMBAT_D->do_attack(me, target, me->query_temp(weapon))
/*                 if(!objectp(target) 
                   || target->is_ghost() 
                   || target->query(eff_kee) < 1
                   || (environment(me)!=environment(target))
                   || me->is_ghost()) 
                                        {       
              message_vision(HIC $N轻颂佛号：“阿弥陀佛，造孽造孽！”，顿时满目凄凉之色。\n NOR, me)
        me->add_temp(apply/damage, -2*t)
        me->add_temp(apply/attack, -t/2)
        me->delete_temp(skill_mark/fumo)
                                                break
                                        }
*/                                                  
                                 }
        me->add_temp(apply/damage, -t/4)
        me->add_temp(apply/attack, -t/2)
        me->add(force, -50)
        target->start_busy(t/20)
        return 1

}
int pfm5(object me, object target)
{
        int t,i,tf,mf,tmf,mmf
        me->delete_temp(skill_mark/fumo)
        if (!me) return 1
        if(!living(target)) return 1
        if (!(objectp(present(target->query(id), environment(me)))))
        return 1

        message_vision( HIW\n$n在$N内力催逼之下不得不改变武功的招数，立时间形成了两人相互比拼内力的局面。\n$N和$n头顶渐渐现出一团淡淡的水气，是额头与顶门汗水为内力所逼，化作了蒸气，\n此时已然是万分凶险，只要内劲被对方一逼上岔路，纵非立时气绝死亡，也当走火入魔，发疯瘫痪。\n NOR, me,target)
        if( mmf > 2*tmf/3)
        {
        message_vision( HIR\n$n眼前一黑，“哇”的吐出一口鲜血，显然在内功修为上与$N上相去甚远！\n NOR, me,target)
        target->unconcious()
        me->add(force, -tmf/2)
        }
        else if( mmf+mf > tmf+tf)
        {
        message_vision( HIB\n$n只觉得内力渐渐周转不足，顿时胸闷气短，一道真气走到了岔道，“啊”的一声，已然走火入魔！”\n NOR, me,target)
        target->add_temp(apply/composure,-1*me->query_cps())
        target->add(eff_kee,-1*target->query(max_kee)/2)
        target->set(force,0)
        me->add(force, -tmf/2)
        }
        else if( mmf+mf <= tmf+tf)
        {
        message_vision( HIY\n$N觉得自己的胸口有如一记重锤，再也提不起真气来，顿时眼冒金星，好似有许多蝴蝶飞来飞去！\n NOR, me,target)
        me->add_temp(apply/composure,-1*me->query_cps())
        me->add(eff_kee,-1*target->query(max_kee)/2)
        me->set(force,0)
        }else{
message_vision( HIG\n$N和$n为对方内力所震，各自退了一步，卸去了膨胀的真气。\n NOR, me,target)
        me->add(force, -mmf/2)
        target->add(force, -tmf/2)
        me->start_busy( 10 )
        target->start_busy( 10 )
        }
        return 1
        
}
