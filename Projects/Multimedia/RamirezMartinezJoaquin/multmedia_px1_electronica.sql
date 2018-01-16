-- phpMyAdmin SQL Dump
-- version 4.5.1
-- http://www.phpmyadmin.net
--
-- Servidor: 127.0.0.1
-- Tiempo de generación: 02-06-2016 a las 21:41:18
-- Versión del servidor: 10.1.10-MariaDB
-- Versión de PHP: 7.0.3

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Base de datos: `multmedia_px1_electronica`
--

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `categorias`
--

CREATE TABLE `categorias` (
  `id` int(11) NOT NULL,
  `categoria` varchar(100) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Volcado de datos para la tabla `categorias`
--

INSERT INTO `categorias` (`id`, `categoria`) VALUES
(1, 'categoria pricipal'),
(3, 'otra categoria (secundaria)');

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `productos`
--

CREATE TABLE `productos` (
  `id` int(11) NOT NULL,
  `id_subcategoria` int(11) NOT NULL,
  `id_provedor` int(11) NOT NULL,
  `nombre` varchar(100) NOT NULL,
  `precio` float NOT NULL,
  `descripcion` text NOT NULL,
  `existencia` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Volcado de datos para la tabla `productos`
--

INSERT INTO `productos` (`id`, `id_subcategoria`, `id_provedor`, `nombre`, `precio`, `descripcion`, `existencia`) VALUES
(1, 3, 3, 'vhvdhgs', 99.99, 'Arriba el ESTADO ISLAMICO (hermanos cyber-califato)', 10),
(2, 1, 1, 'dcsc', 100, '', 0);

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `provedores`
--

CREATE TABLE `provedores` (
  `id` int(11) NOT NULL,
  `nombre` varchar(50) NOT NULL,
  `telefono` varchar(10) NOT NULL,
  `correo` varchar(60) NOT NULL,
  `direccion` text NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Volcado de datos para la tabla `provedores`
--

INSERT INTO `provedores` (`id`, `nombre`, `telefono`, `correo`, `direccion`) VALUES
(1, 'steren', '9999999999', 'mailme@fake.it', 'N/A'),
(3, 'nuevo prov', '', '', '');

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `roles`
--

CREATE TABLE `roles` (
  `id` int(11) NOT NULL,
  `rol` varchar(100) NOT NULL,
  `fecha_creacion` date NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Volcado de datos para la tabla `roles`
--

INSERT INTO `roles` (`id`, `rol`, `fecha_creacion`) VALUES
(1, 'Administrador', '2016-05-20'),
(2, 'Vendedor', '2016-05-31');

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `subcategorias`
--

CREATE TABLE `subcategorias` (
  `id` int(11) NOT NULL,
  `id_categoria` int(11) NOT NULL,
  `subcategoria` varchar(100) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Volcado de datos para la tabla `subcategorias`
--

INSERT INTO `subcategorias` (`id`, `id_categoria`, `subcategoria`) VALUES
(1, 3, 'mi subcat'),
(3, 1, 'otro');

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `usuarios`
--

CREATE TABLE `usuarios` (
  `id` int(11) NOT NULL,
  `id_rol` int(11) NOT NULL,
  `nombre` varchar(100) NOT NULL,
  `ap_paterno` varchar(50) NOT NULL,
  `ap_materno` varchar(50) NOT NULL,
  `sexo` char(1) NOT NULL,
  `telefono` varchar(10) NOT NULL,
  `correo` varchar(60) NOT NULL,
  `entradas` int(11) NOT NULL,
  `fecha_ultima_entrada` date NOT NULL,
  `usuario` varchar(100) NOT NULL,
  `password` varchar(100) NOT NULL,
  `fecha_creacion` date NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Volcado de datos para la tabla `usuarios`
--

INSERT INTO `usuarios` (`id`, `id_rol`, `nombre`, `ap_paterno`, `ap_materno`, `sexo`, `telefono`, `correo`, `entradas`, `fecha_ultima_entrada`, `usuario`, `password`, `fecha_creacion`) VALUES
(2, 2, 'Mia', 'Khalifa', 'de Lopez', 'M', '7710201133', 'mia_97@outlook.com', 1, '2016-05-14', 'kali', 'kali', '2016-05-14'),
(9, 1, 'Joaquin', 'Ramirez', 'Martinez', 'H', '7721108109', 'joaquin.ramirez.mtz.lab@hotmail.com', 0, '2016-05-14', 'admin', 'admin', '2016-05-14');

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `venta`
--

CREATE TABLE `venta` (
  `id` int(11) NOT NULL,
  `id_ventas` int(11) NOT NULL,
  `id_producto` int(11) NOT NULL,
  `cantidad_producto` int(11) NOT NULL,
  `precio_unitario` float NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Volcado de datos para la tabla `venta`
--

INSERT INTO `venta` (`id`, `id_ventas`, `id_producto`, `cantidad_producto`, `precio_unitario`) VALUES
(1, 1, 1, 0, 99.99),
(2, 1, 2, 0, 100);

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `ventas`
--

CREATE TABLE `ventas` (
  `id` int(11) NOT NULL,
  `fecha` date NOT NULL,
  `nota` text NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Volcado de datos para la tabla `ventas`
--

INSERT INTO `ventas` (`id`, `fecha`, `nota`) VALUES
(1, '2016-06-02', '');

--
-- Índices para tablas volcadas
--

--
-- Indices de la tabla `categorias`
--
ALTER TABLE `categorias`
  ADD PRIMARY KEY (`id`),
  ADD UNIQUE KEY `categoria` (`categoria`);

--
-- Indices de la tabla `productos`
--
ALTER TABLE `productos`
  ADD PRIMARY KEY (`id`);

--
-- Indices de la tabla `provedores`
--
ALTER TABLE `provedores`
  ADD PRIMARY KEY (`id`);

--
-- Indices de la tabla `roles`
--
ALTER TABLE `roles`
  ADD PRIMARY KEY (`id`),
  ADD UNIQUE KEY `rol` (`rol`);

--
-- Indices de la tabla `subcategorias`
--
ALTER TABLE `subcategorias`
  ADD PRIMARY KEY (`id`),
  ADD UNIQUE KEY `subcategoria` (`subcategoria`);

--
-- Indices de la tabla `usuarios`
--
ALTER TABLE `usuarios`
  ADD PRIMARY KEY (`id`),
  ADD UNIQUE KEY `usuario` (`usuario`);

--
-- Indices de la tabla `venta`
--
ALTER TABLE `venta`
  ADD PRIMARY KEY (`id`);

--
-- Indices de la tabla `ventas`
--
ALTER TABLE `ventas`
  ADD PRIMARY KEY (`id`);

--
-- AUTO_INCREMENT de las tablas volcadas
--

--
-- AUTO_INCREMENT de la tabla `categorias`
--
ALTER TABLE `categorias`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=4;
--
-- AUTO_INCREMENT de la tabla `productos`
--
ALTER TABLE `productos`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=3;
--
-- AUTO_INCREMENT de la tabla `provedores`
--
ALTER TABLE `provedores`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=4;
--
-- AUTO_INCREMENT de la tabla `roles`
--
ALTER TABLE `roles`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=3;
--
-- AUTO_INCREMENT de la tabla `subcategorias`
--
ALTER TABLE `subcategorias`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=4;
--
-- AUTO_INCREMENT de la tabla `usuarios`
--
ALTER TABLE `usuarios`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=10;
--
-- AUTO_INCREMENT de la tabla `venta`
--
ALTER TABLE `venta`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=3;
--
-- AUTO_INCREMENT de la tabla `ventas`
--
ALTER TABLE `ventas`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=2;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
