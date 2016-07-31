#ifndef INCLUDED_AC_PLAYER_H
#define INCLUDED_AC_PLAYER_H

class ACPlayer
{
    private:
        LL_AL5::Sprite _V_car;
        float _V_max_speed=PLAYER_MAX_SPEED;
        float _V_limit_x_1;
        float _V_limit_x_2;
        float _V_limit_y_1;
        float _V_limit_y_2;
    public:
        ACPlayer()
        {
            _V_car.set_centering_option(true,true);
            _V_car.set_size(TOTAL_PLAYER_SPRITES);
        }
        void set_limits(float limit_x_1,float limit_x_2,float limit_y_1,float limit_y_2)
        {
            _V_limit_x_1=limit_x_1;
            _V_limit_x_2=limit_x_2;
            _V_limit_y_1=limit_y_1;
            _V_limit_y_2=limit_y_2;
        }
        bool create_sprite()
        {
            if(_V_car.create())
            {
                string sprite_path;
                switch(ac_car_type)
                {
                    case CAR_TYPE_AUTO:
                    {
                        sprite_path=AUTO_SPRITE_PATH;
                        break;
                    }
                    case CAR_TYPE_AC_CAR:
                    {
                        sprite_path=AC_CAR_SPRITE_PATH;
                        break;
                    }
                    case CAR_TYPE_FORMULA:
                    {
                        sprite_path=FORMULA_SPRITE_PATH;
                        break;
                    }
                }
                if(_V_car.create_data_from_directory(sprite_path,BMP_FORMAT))
                {
                    LL_AL5::Color paint_color;
                    switch(ac_car_color)
                    {
                        case CAR_COLOR_BLACK:
                        {
                            paint_color=BLACK;
                            break;
                        }
                        case CAR_COLOR_BLUE:
                        {
                            paint_color=BLUE;
                            break;
                        }
                        case CAR_COLOR_GREEN:
                        {
                            paint_color=GREEN;
                            break;
                        }
                        case CAR_COLOR_RED:
                        {
                            paint_color=RED;
                            break;
                        }
                        case CAR_COLOR_YELLOW:
                        {
                            paint_color=YELLOW;
                            break;
                        }
                        case CAR_COLOR_WHITE:
                        {
                            paint_color=WHITE;
                            break;
                        }
                    }
                    for(unsigned int i=0;i<TOTAL_PLAYER_SPRITES;++i)
                    {
                        _V_car.set_selection(i);
                        _V_car.lock();
                        _V_car.set_target();
                        for(unsigned int x=0;x<_V_car.get_size_x();++x)
                        {
                            for(unsigned int y=0;y<_V_car.get_size_y();++y)
                            {
                                if(TURQUOISE==_V_car.get_pixel_color(x,y))
                                    al_put_pixel(x,y,paint_color);
                            }
                        }
                        _V_car.unlock();
                    }
                    screen->set_target();
                    return true;
                }
                _V_car.destroy();
            }
            return false;
        }
        bool set_selection(unsigned int new_selection)
        {
            return _V_car.set_selection(new_selection);
        }
        LL_AL5::Type_pos get_pos_x()
        {
            return _V_car.get_pos_x();
        }
        LL_AL5::Type_pos get_pos_y()
        {
            return _V_car.get_pos_y();
        }
        void set_pos(LL_AL5::Type_pos new_pos_x,LL_AL5::Type_pos new_pos_y)
        {
            _V_car.set_pos(new_pos_x,new_pos_y);
        }
        void draw()
        {
            _V_car.draw();
        }
        void move(int move_x,int move_y)
        {
            _V_car.set_pos(_V_car.get_pos_x()+move_x*_V_max_speed,
                           _V_car.get_pos_y()+move_y*_V_max_speed);
            if(_V_car.get_pos_x()<_V_limit_x_1)
                _V_car.set_pos_x(_V_limit_x_1);
            else if(_V_car.get_pos_x()>_V_limit_x_2)
                _V_car.set_pos_x(_V_limit_x_2);
            if(_V_car.get_pos_y()<_V_limit_y_1)
                _V_car.set_pos_y(_V_limit_y_1);
            else if(_V_car.get_pos_y()>_V_limit_y_2)
                _V_car.set_pos_y(_V_limit_y_2);
        }
};

#endif // INCLUDED_AC_PLAYER_H
