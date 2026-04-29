// tm_poison.c

#include <ansi.h>
#include <skill.h>

int update_condition(object me, int duration)
{
        int time;

        if( duration < 1 ) return 0;

        if( me->query_condition("ninemoonpoison") && me->query_condition("rose_poison") )
        {
                time += me->query_condition("ninemoonpoison");
                time += me->query_condition("rose_poison");             
                time += me->query_condition("tm_poison");
                time /= 2;
                if( time < 10 ) time = 10;
                me->apply_condition("super_poisons",time);
                me->apply_condition("tm_poison",0);
                me->apply_condition("ninemoonepoison",0);
                me->apply_condition("rose_poison",0);           
                return 1;
        }
                        
        me->receive_wound("sen", duration*5);
        me->receive_wound("kee", duration*20);
        me->receive_wound("gin", duration*5);
        if(me->query_skill("taiji-shengong",1) > 0 || me->query_skill("hunyuan-yiqi",1) > 0 )
        me->receive_wound("kee", duration*20);

        if( me->query_skill("dugong",1) >= 100 )
                me->apply_condition("tm_poison", duration / 2);
        else
                me->apply_condition("tm_poison", duration - 1);

        tell_object(me, HIR "你中的" GRN "唐门无影毒" HIR "发作了！\n" NOR );
        message_vision(HIG"$N的脸上泛起一阵绿光, 身子不由自主地摇晃了一下.\n"NOR,me);

        return 1;
}

