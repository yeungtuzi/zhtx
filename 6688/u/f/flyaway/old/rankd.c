// rankd.c
// Update by dongsw

#include <ansi.h>

string query_rank(object ob)
{
        string bangname,bangrank,tmpstr;

        //if( (wiz_level(ob)||raw_wiz_level(ob)) && (bangname = ob->query("custom_rank")) )
        //                                        return HIG"【"+bangname+"】" NOR;
        if( ob->is_ghost() ) return HIB "【 鬼  魂 】" NOR;
        if(ob->query("PKS")>=100)               return HIR "【 杀人魔 】"NOR;

        bangname = ob->query("marks/帮派");
        if (bangname!=0) {
                tmpstr = "marks/" + bangname;
                bangrank = ob->query(tmpstr);
                return HIB"【 "+bangname+bangrank+"】" NOR;
        }

        if( ob->query("gender") == "无性" )
                                                return HIC "【 太  监 】" NOR;
        switch(ob->query("gender")) {
        case "女性":
        switch(wizhood(ob)) {
                case "(admin)":                 return HIW "【 女  神 】" NOR;
                case "(arch)":                  return HIY "【 大魔女 】" NOR;
                case "(wizard)":                return HIG "【 魔  女 】" NOR;
                case "(apprentice)":            return HIC "【 小魔女 】" NOR;
                case "(immortal)":              return HIC "【 仙  女 】" NOR;
                default:
        if( ((int)ob->query("PKS") > 100))
                return HIR"【 杀人魔 】"NOR;
        if( (int)ob->query("thief") > 10 ) return HIR"【 惯  窃 】"NOR;
        switch(ob->query("class")) {
                case "bonze":
                if ((int)ob->query("combat_exp")<10000)   return "【 小尼姑 】";
                if ((int)ob->query("combat_exp")<50000)   return CYN"【 沙弥尼 】"NOR;
                if ((int)ob->query("combat_exp")<200000)  return CYN"【 尼  姑 】"NOR;
                if ((int)ob->query("combat_exp")<1000000) return CYN"【 师  太 】"NOR;
                if ((int)ob->query("combat_exp")<5000000) return CYN"【 神  尼 】"NOR;
                else return CYN"【 菩  萨 】"NOR;
                case "taoist":
                if ((int)ob->query("combat_exp")<10000)   return "【 小道姑 】";
                if ((int)ob->query("combat_exp")<100000)  return "【 小女冠 】";
                if ((int)ob->query("combat_exp")<1000000) return "【 大女冠 】";
                if ((int)ob->query("combat_exp")<5000000) return "【 女真人 】";
                else return "【 女掌教 】";
                case "bandit":          return HIR"【 女飞贼 】"NOR;
                case "dancer":
                if ((int)ob->query("combat_exp")<10000)   return "【 女  仆 】";
                if ((int)ob->query("combat_exp")<100000)  return CYN"【 女学徒 】"NOR;
                if ((int)ob->query("combat_exp")<500000)  return CYN"【 歌  妓 】"NOR;
                if ((int)ob->query("combat_exp")<1000000) return CYN"【 舞  妓 】"NOR;
                else return CYN"【 女庄主 】"NOR;

                case "legend":                            return "【 侠  女 】";
                case "scholar":
                        if((int)ob->query("combat_exp")<10000)return WHT"【 女  仆 】"NOR;
                        if((int)ob->query("combat_exp")<50000)return WHT"【 女学徒 】"NOR;
                        if((int)ob->query("combat_exp")<100000)return WHT"【 才  女 】"NOR;
                        if((int)ob->query("combat_exp")<500000)return HIW"【 女剑客 】"NOR;
                        if((int)ob->query("combat_exp")<1000000)return HIW"【 女剑仙 】"NOR;
                        else return HIW"【 副庄主 】"NOR;
                case "officer":         return "【 女  官 】";
                case "fighter":
                        if((int)ob->query("combat_exp")<10000)return "【 女武者 】";
                        if((int)ob->query("combat_exp")<100000)return HIR"【 女武士 】"NOR;
                        if((int)ob->query("combat_exp")<1000000)return HIR"【 女斗士 】"NOR;
                        else return HIR"【 女武神 】"NOR;
                case "swordsman":
                if((int)ob->query("combat_exp")<10000)return "【 女剑士 】";
                if((int)ob->query("combat_exp")<100000)return HIC"【 女剑侠 】"NOR;
                if((int)ob->query("combat_exp")<1000000)return HIC"【 女剑圣 】"NOR;
                else return HIC"【 女剑仙 】"NOR;
                case "alchemist":       return YEL"【 方  士 】"NOR;
                case "ninemoon":    return RED"【 邪  女 】"NOR;
                case "shaman":          return RED"【 巫  医 】"NOR;
                case "lama":            return CYN"【 藏  尼 】"NOR;
                case "beggar":          return WHT"【 叫化子 】"NOR;
                default:
                        switch(ob->query("family/family_name"))
                        {
                                case "华山派" :
                if((int)ob->query("combat_exp")<10000)return "【 女剑士 】";
                if((int)ob->query("combat_exp")<100000)return HIC"【 女剑侠 】"NOR;
                if((int)ob->query("combat_exp")<1000000)return HIC"【 女剑圣 】"NOR;
                if((int)ob->query("combat_exp")<5000000)return HIC"【 女剑仙 】"NOR;
                else return HIC"【 女剑魔 】"NOR;

                                case "丐帮":
                if((int)ob->query("combat_exp")<10000)return "【 小叫花 】";
                if((int)ob->query("combat_exp")<100000)return "【 叫花妇 】";
                if((int)ob->query("combat_exp")<1000000)return "【 女丐侠 】";
                else return "【 女神丐 】";

                                case "日月神教":
                                        if( (int)ob->query("family/generation") <= 15 )
                                                return HIG"【 圣  姑 】"NOR;
                                        else    return HIM"【 魔  女 】"NOR;
                                case "天邪派":
                        if((int)ob->query("combat_exp")<10000)return "【 女武者 】";
                        if((int)ob->query("combat_exp")<100000)return HIR"【 女武士 】"NOR;
                        if((int)ob->query("combat_exp")<1000000)return HIR"【 女斗士 】"NOR;
                        else return HIR"【 女武神 】"NOR;

                                case "铁血大旗门":      return HIM"【 神  女 】"NOR;

                                case "明教":
                        if((int)ob->query("combat_exp")<10000)return "【 女弟子 】";
                        if((int)ob->query("combat_exp")<100000)return HIY"【 女旗主 】"NOR;
                        if((int)ob->query("combat_exp")<1000000)return HIY"【 女堂主 】"NOR;
                        if((int)ob->query("combat_exp")<5000000)return HIY"【 女长老 】"NOR;
                                else return HIY"【 女法王 】"NOR;

                                case "星宿派":  return HIY"【 妖  女 】"NOR;

                                case "桃花岛" : return HIG"【 仙  子 】"NOR;

                                default:
                                        return "【 平  民 】";
                        }

                }
        }
        default:
        switch(wizhood(ob)) {
                case "(admin)":                 return HIW "【 天  神 】" NOR;
                case "(arch)":                  return HIY "【 大巫师 】" NOR;
                case "(wizard)":                return HIG "【 巫  师 】" NOR;
                case "(apprentice)":    return HIC "【巫师学徒】" NOR;
                case "(immortal)":              return HIC "【 仙  人 】" NOR;
                default:
                if( ((int)ob->query("PKS") > 100) &&
                ((int)ob->query("PKS") > (int)ob->query("MKS")) )
                        return "【 杀人魔 】";
                if( (int)ob->query("thief") > 10 ) return "【 惯  窃 】";
                switch(ob->query("class")) {
                case "bonze":
                        if((int)ob->query("combat_exp")<10000)return YEL"【 僧  人 】"NOR;
                        if((int)ob->query("combat_exp")<50000)return YEL"【 比  丘 】"NOR;
                        if((int)ob->query("combat_exp")<100000)return YEL"【 尊  者 】"NOR;
                        if((int)ob->query("combat_exp")<200000)return YEL"【 禅  师 】"NOR;
                        if((int)ob->query("combat_exp")<500000)return HIY"【 高  僧 】"NOR;
                        if((int)ob->query("combat_exp")<1000000)return HIY"【 罗  汉 】"NOR;
                        if((int)ob->query("combat_exp")<2000000)return HIY"【 神  僧 】"NOR;
                        if((int)ob->query("combat_exp")<5000000)return HIY"【 活  佛 】"NOR;
                        else return HIY"【  达摩  】"NOR;
                case "taoist":          return "【 道  士 】";
                case "bandit":          return HIR"【 盗  贼 】"NOR;
                case "scholar":         return "【 书  生 】";
                        if((int)ob->query("combat_exp")<10000)return WHT"【 仆  人 】"NOR;
                        if((int)ob->query("combat_exp")<50000)return WHT"【 学  徒 】"NOR;
                        if((int)ob->query("combat_exp")<100000)return WHT"【 才  子 】"NOR;
                        if((int)ob->query("combat_exp")<500000)return HIW"【 剑  客 】"NOR;
                        if((int)ob->query("combat_exp")<1000000)return HIW"【 剑  仙 】"NOR;
                        else return HIW"【 副庄主 】"NOR;
                case "legend":      return "【 游  侠 】";
                case "officer":         return "【 官  差 】";
                case "fighter":
                        if((int)ob->query("combat_exp")<10000)return "【 武  者 】";
                        if((int)ob->query("combat_exp")<100000)return HIR"【 武  士 】"NOR;
                        if((int)ob->query("combat_exp")<500000)return HIR"【 斗  士 】"NOR;
                        else return HIR"【 武  神 】"NOR;
                case "swordsman":
                        if((int)ob->query("combat_exp")<10000)return "【 剑  士 】";
                        if((int)ob->query("combat_exp")<100000)return HIC"【 剑  侠 】"NOR;
                        if((int)ob->query("combat_exp")<500000)return HIC"【 剑  圣 】"NOR;
                        else return HIC"【 剑  神 】"NOR;
                case "alchemist":       return YEL"【 方  士 】"NOR;
                case "shaman":          return RED"【 巫  医 】"NOR;
                case "lama":
                        if((int)ob->query("combat_exp")<10000)return YEL"【 藏  僧   】"NOR;
                        if((int)ob->query("combat_exp")<50000)return YEL"【 比  丘 】"NOR;
                        if((int)ob->query("combat_exp")<100000)return YEL"【 尊  者 】"NOR;
                        if((int)ob->query("combat_exp")<200000)return YEL"【 禅  师 】"NOR;
                        if((int)ob->query("combat_exp")<500000)return HIY"【 高  僧 】"NOR;
                        if((int)ob->query("combat_exp")<1000000)return HIY"【 罗  汉 】"NOR;
                        if((int)ob->query("combat_exp")<2000000)return HIY"【 神  僧 】"NOR;
                        if((int)ob->query("combat_exp")<5000000)return HIY"【 活  佛 】"NOR;
                case "beggar":          return "【 叫化子 】";
                default:
                        switch(ob->query("family/family_name"))
                        {
                                case "华山派" :
                        if((int)ob->query("combat_exp")<10000)return "【 剑  士 】";
                        if((int)ob->query("combat_exp")<100000)return HIC"【 剑  侠 】"NOR;
                        if((int)ob->query("combat_exp")<500000)return HIC"【 剑  圣 】"NOR;
                        else return HIC"【 剑  神 】"NOR;
                                case "丐帮":
                        if((int)ob->query("combat_exp")<10000)return "【 小叫花 】";
                        if((int)ob->query("combat_exp")<100000)return HIC"【 讨饭花 】"NOR;
                        if((int)ob->query("combat_exp")<200000)return HIC"【 乞  丐 】"NOR;
                        if((int)ob->query("combat_exp")<100000)return HIC"【 侠  丐 】"NOR;
                        else return HIC"【 神  丐 】"NOR;
                                case "日月神教":
                                        if( (int)ob->query("family/generation") <= 15 )
                                                return HIG"【 神  魔 】"NOR;
                                        else    return HIM"【 魔  头 】"NOR;
                                case "天邪派":
                        if((int)ob->query("combat_exp")<10000)return "【 武  者 】";
                        if((int)ob->query("combat_exp")<100000)return HIR"【 武  士 】"NOR;
                        if((int)ob->query("combat_exp")<500000)return HIR"【 斗  士 】"NOR;
                        else return HIR"【 武  神 】"NOR;
                                case "铁血大旗门" :
                                        if((int)ob->query("combat_exp")<200000)return "【 战  士 】";
                                        else return HIG"【冷血战神】"NOR;
                                case "明教":
                        if((int)ob->query("combat_exp")<10000)return "【 弟  子 】";
                        if((int)ob->query("combat_exp")<100000)return HIY"【 旗  主 】"NOR;
                        if((int)ob->query("combat_exp")<1000000)return HIY"【 堂  主 】"NOR;
                        if((int)ob->query("combat_exp")<5000000)return HIY"【 长  老 】"NOR;
                                else return HIY"【 法  王 】"NOR;
                                case "星宿派":  return HIY"【 邪  士 】"NOR;
                                case "桃花岛" :
                                        if((int)ob->query("combat_exp")<50000)return "【 逸  士 】";
                                        else return HIC"【 逸  仙 】"NOR;
                                default:
                                        return "【 平  民 】";
                        }
                }
            }
        }
}

string query_respect(object ob)
{
        int age;
        string str;

        if(!ob) return "";
        if( stringp(str = ob->query("rank_info/respect")) )
                return str;

        age = ob->query("age");
        switch(ob->query("gender")) {
                case "女性":
                        switch(ob->query("class")) {
                        case "bonze":
                                if( age < 18 ) return "小师太";
                                else return "师太";
                                break;
                        case "taoist":
                                if( age < 18 ) return "小仙姑";
                                else return "仙姑";
                                break;
                        default:
                                if( age < 18 ) return "小姑娘";
                                else if( age < 50 ) return "姑娘";
                                else return "婆婆";
                                break;
                        }
                case "男性":
                default:
                        switch(ob->query("class")) {
                        case "bonze":
                                if( age < 18 ) return "小师父";
                                else return "大师";
                                break;
                        case "taoist":
                                if( age < 18 ) return "道兄";
                                else return "道长";
                                break;
                        case "fighter":
                        case "swordsman":
                                if( age < 18 ) return "小老弟";
                                else if( age < 50 ) return "壮士";
                                else return "老前辈";
                                break;
                        default:
                                if( age < 20 ) return "小兄弟";
                                else if( age < 50 ) return "壮士";
                                else return "老爷子";
                                break;
                        }
        }
}

string query_rude(object ob)
{
        int age;
        string str;

        if(!ob) return "";
        if( stringp(str = ob->query("rank_info/rude")) )
                return str;

        age = ob->query("age");
        switch(ob->query("gender")) {
                case "女性":
                        switch(ob->query("class")) {
                        case "bonze":
                                return "贼尼";
                                break;
                        case "taoist":
                                return "妖女";
                                break;
                        default:
                                if( age < 30 ) return "小贱人";
                                if( age < 45 ) return "贱人";
                                else return "死老太婆";
                                break;
                        }
                case "男性":
                default:
                        switch(ob->query("class")) {
                        case "bonze":
                                if( age < 50 ) return "死秃驴";
                                else return "老秃驴";
                                break;
                        case "taoist":
                                return "死牛鼻子";
                                break;
                        default:
                                if( age < 20 ) return "小王八蛋";
                                if( age < 50 ) return "臭贼";
                                else return "老匹夫";
                                break;
                        }
        }
}

string query_self(object ob)
{
        int age;
        string str;

        if( stringp(str = ob->query("rank_info/self")) )
                return str;

        age = ob->query("age");
        switch(ob->query("gender")) {
                case "女性":
                        switch(ob->query("class")) {
                        case "bonze":
                                if( age < 50 ) return "贫尼";
                                else return "老尼";
                                break;
                        default:
                                if( age < 30 ) return "小女子";
                                else return "妾身";
                                break;
                        }
                case "男性":
                default:
                        switch(ob->query("class")) {
                        case "bonze":
                                if( age < 50 ) return "贫僧";
                                else return "老纳";
                                break;
                        case "taoist":
                                return "贫道";
                                break;
                        default:
                                if( age < 30 ) return "小生";
                                if( age < 50 ) return "在下";
                                else return "老夫";
                                break;
                        }
        }
}

string query_self_rude(object ob)
{
        int age;
        string str;

        if( stringp(str = ob->query("rank_info/self_rude")) )
                return str;

        age = ob->query("age");
        switch(ob->query("gender")) {
                case "女性":
                        switch(ob->query("class")) {
                        case "bonze":
                                if( age < 50 ) return "贫尼";
                                else return "老尼";
                                break;
                        default:
                                if( age < 30 ) return "本姑娘";
                                else return "老娘";
                                break;
                        }
                case "男性":
                default:
                        switch(ob->query("class")) {
                        case "bonze":
                                if( age < 50 ) return "大和尚我";
                                else return "老和尚我";
                                break;
                        case "taoist":
                                return "本山人";
                                break;
                        default:
                                if( age < 50 ) return "大爷我";
                                else return "老子";
                                break;
                        }
        }
}
//write by Huang (11/02/96)
string query_guanxi(object me,object target)
{
        int me_age,target_age;
        string str;

        if( stringp(str = me->query("rank_info/guanxi")) )
                return str;

        me_age = me->query("age");
        if ( stringp(str = target->query("rank_info/guanxi")) )
                return str;
        else target_age = target->query("age");

        switch(me->query("gender")) {
                case "女性":
                        if (me_age > target_age) return "姐姐";
                        else return "妹妹";
                        break;
                case "男性":
                        if (me_age > target_age) return "哥哥";
                        else return "弟弟";
                        break;
                default:
                        return "公公";
                        break;
        }
}

string query_close(object ob)
{
        int a1, a2;

        if (objectp(ob))
        {
                if (a2 = (int)ob->query("mud_age"))
                {
                        a1 = this_player()->query("mud_age");
                } else
                {
                        a1 = this_player()->query("age");
                        a2 = ob->query("age");
                }
        } else
        {
                a1 = this_player()->query("age");
                a2 = 0;
        }


        switch (ob->query("gender")) {
        case "女性" :
                if (a1 >= a2) return "妹妹";
                else
                        return "姐姐";
                break;
        default :
                if (a1 >= a2)
                        return "弟弟";
                else
                        return "哥哥";
        }
}


string query_per(object ob)
{
 int per;
 int age;
 age=(int)ob->query("age");
 switch(ob->query("gender")){
                            case "男性":
                            if(age<18) return "少年";
                            if(age>=18&&age<45) return "男子";
                            else return "老者";
                            break;

                            case "女性":
                            if(age<18) return "女孩";
                            if(age>=18&&age<30) return "姑娘";
                            if(age>=30&&age<=45) return "女子";
                            else return "老太太";
                            case "无性":
                            if(age<18) return "小公公";
                            if(age>=18&&age<40) return "公公";
                            else return "老公公";
                           }
}

//原来这里返回值是错的
// yeung
string query_self_close(object ob)
{
        int a1, a2;
/*
        程序什么意思？

        if (objectp(ob))
        {
                if (a2 = (int)ob->query("mud_age"))
                {
                        a1 = this_player()->query("mud_age");
                } else
                {
                        a1 = this_player()->query("age");
                        a2 = ob->query("age");
                }
        } else
        {
                a1 = this_player()->query("age");
                a2 = 0;
        }
*/
        a1 = this_player()->query("age");
        a2 = ob->query("age");

        switch (this_player()->query("gender")) {
        case "女性" :
                if (a1 >= a2)
                        return "姐姐我";
                else
                        return "小妹我";
                break;
        default :
                if (a1 >= a2)
                        return "愚兄我";
                else
                        return "小弟我";
        }
}

